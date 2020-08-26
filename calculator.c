#include <math.h>
#include <gtk-3.0/gtk/gtk.h>
#include <string.h>
#include "cHeaderFiles/calculatorButtons.h"
#include <iso646.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define FLOAT_TEXT_WIDTH 31

GtkWidget *textview;
GtkTextBuffer *buffer;

void cssButtons(void);

void buttonExit() {
    exit(0);
}

size_t strchrcount(char *string, char search) {
    size_t count = 0;
    while (*string != 0) {
        if (*string == search) count++;
        string++;
    }
    return count;
}

void strcharsreplace (char *string, char character, char replace_to) {
    while(*string != 0) {
        if (*string == character) *string = replace_to;
        string++;
    }
}

static void validate_and_calc() {
    GtkTextIter start_iter, end_iter;
    gtk_text_buffer_get_start_iter (buffer, &start_iter);
    gtk_text_buffer_get_end_iter (buffer, &end_iter);
    gchar *field = gtk_text_buffer_get_text(buffer, &start_iter, &end_iter, 0);

    if (strspn(field, "12345678901+-*/.,") != strlen(field)) {
        gtk_text_buffer_set_text(buffer, "Bad expression!", -1);
        return;
    }
    strcharsreplace(field, ',', '.');
    if (strchrcount(field, '.') > 2) {
        gtk_text_buffer_set_text(buffer, "Too much dots!", -1);
        return;
    }

    char *operator = field + strcspn(field, "+-*/");
    if (strchrcount(field, *operator) > 1) {
        gtk_text_buffer_set_text(buffer, "Too much operators!", -1);
        return;
    }
    if (!isdigit(operator[1]) or !isdigit(operator[-1])) {
        char malformed_expression_at_operator[] = {"Malformed expression at 1 operator!"};
        malformed_expression_at_operator[24] = *operator;
        gtk_text_buffer_set_text(buffer, malformed_expression_at_operator, -1);
        return;
    }
    char op = *operator;
    *operator = 0;
    char *dot1 = strchr(field, '.');
    char *dot2 = strchr(operator + 1, '.');
    double operand1;
    double operand2;

    if(dot1 != NULL) {
        if (!isdigit(dot1[1]) or !isdigit(dot1[-1])) {
            gtk_text_buffer_set_text(buffer, "Malformed expression at dot symbol!", -1);
            return;
        }
        *dot1 = 0;
        operand1 = strtol(field, NULL, 10) + strtol(dot1 + 1, NULL, 10) / pow(10, strlen(dot1 + 1)); //c89 compat
    } else {
        operand1 = strtol(field, NULL, 10);
    }

    if(dot2 != NULL) {
        if (!isdigit(dot2[1]) or !isdigit(dot2[-1])) {
            gtk_text_buffer_set_text(buffer, "Malformed expression at dot symbol!", -1);
            return;
        }
        *dot2 = 0;
        operand2 = strtol(operator+1, NULL, 10) + strtol(dot2 + 1, NULL, 10) / pow(10, strlen(dot2 + 1));
    } else {
        operand2 = strtol(operator+1, NULL, 10);
    }

    static double result;

    switch (op) {
        case '/':
            if (operand2 == (float) 0) {
                gtk_text_buffer_set_text(buffer, "Division by zero!", -1);
                return;
            }
            result = operand1 / operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        default:
            return;
    }

    char result_str[FLOAT_TEXT_WIDTH];
    memset(result_str, 0, FLOAT_TEXT_WIDTH);
    snprintf(result_str, FLOAT_TEXT_WIDTH, "%g", result);
    gtk_text_buffer_set_text(buffer, result_str, (gint) strlen(result_str));
}

static gboolean key_event(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    int hwcode = event->hardware_keycode;
    if (hwcode == HW_ENTER_KEYCODE or hwcode == HW_NUM_ENTER_KEYCODE) {
        validate_and_calc();
        return TRUE;
    }
    if (hwcode == HW_ESC_KEYCODE) {
        gtk_text_buffer_set_text(buffer, "", 0);
        return TRUE;
    }
    return FALSE;
}

static void add_number (unsigned char number) {
    char insert[2] = {0, 0};
    insert[0] = number + (char)'0';
    gtk_text_buffer_insert_at_cursor(buffer, insert, 1);
}

static void button_exec (GtkWidget *widget, unsigned char *action_num) {
    switch (*action_num) {
        case BUTTON_ONE:
            add_number(BUTTON_ONE);
            break;
        case BUTTON_TWO:
            add_number(BUTTON_TWO);
            break;
        case BUTTON_THREE:
            add_number(BUTTON_THREE);
            break;
        case BUTTON_FOUR:
            add_number(BUTTON_FOUR);
            break;
        case BUTTON_FIVE:
            add_number(BUTTON_FIVE);
            break;
        case BUTTON_SIX:
            add_number(BUTTON_SIX);
            break;
        case BUTTON_SEVEN:
            add_number(BUTTON_SEVEN);
            break;
        case BUTTON_EIGHT:
            add_number(BUTTON_EIGHT);
            break;
        case BUTTON_NINE:
            add_number(BUTTON_NINE);
            break;
        case BUTTON_ZERO:
            add_number(BUTTON_ZERO);
            break;
        case BUTTON_DOT:
            gtk_text_buffer_insert_at_cursor(buffer, ".", 1);
            break;
        case BUTTON_AC:
            gtk_text_buffer_set_text(buffer, "", 0);
            break;
        case BUTTON_PLUS:
            gtk_text_buffer_insert_at_cursor(buffer, "+", 1);
            break;
        case BUTTON_MINUS:
            gtk_text_buffer_insert_at_cursor(buffer, "-", 1);
            break;
        case BUTTON_DIVIS:
            gtk_text_buffer_insert_at_cursor(buffer, "/", 1);
            break;
        case BUTTON_MULTIP:
            gtk_text_buffer_insert_at_cursor(buffer, "*", 1);
            break;
        case BUTTON_EXEC:
            validate_and_calc();
            break;
        default: g_printerr("%d", *action_num);
    }
    gtk_widget_grab_focus(textview);
}

GtkWidget *place_and_bind_button (const gchar *btn_label, void (*handler), gpointer handled_object, GtkWidget *placer, gint left, gint top, gint width, gint height) {
    GtkWidget *btn_ptr = gtk_button_new_with_label(btn_label);
    g_signal_connect (btn_ptr, "clicked", G_CALLBACK (handler), handled_object);
    gtk_grid_attach(GTK_GRID(placer), btn_ptr, left, top, width, height);
    return btn_ptr;
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_fullscreen(GTK_WINDOW(window));

    gtk_container_set_border_width (GTK_CONTAINER (window), 3);

    GtkWidget *grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), grid);

    GtkWidget *scrolled = gtk_scrolled_window_new (NULL, NULL);
    gtk_widget_set_hexpand (scrolled, TRUE);
    gtk_widget_set_vexpand (scrolled, TRUE);
    gtk_grid_attach(GTK_GRID(grid), scrolled, 0, 0, 4, 1);
    gtk_widget_set_size_request(scrolled, 300, 50);
    gtk_scrolled_window_set_policy((GtkScrolledWindow*) scrolled, GTK_POLICY_ALWAYS, GTK_POLICY_AUTOMATIC);
    gtk_widget_set_visible(gtk_scrolled_window_get_hscrollbar((GtkScrolledWindow*)scrolled), FALSE);

    textview = gtk_text_view_new ();
    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview));

    PangoFontDescription *fnt_desc = pango_font_description_from_string("Tahoma 16");
    gtk_widget_modify_font (textview, fnt_desc);
    pango_font_description_free(fnt_desc);

    gtk_text_view_set_justification(GTK_TEXT_VIEW(textview), GTK_JUSTIFY_RIGHT);
    gtk_widget_set_margin_bottom(textview, 5);
    gtk_widget_set_margin_left(textview, 5);
    gtk_widget_set_margin_right(textview, 5);
    gtk_widget_set_margin_top(textview, 5);
    gtk_container_add(GTK_CONTAINER(scrolled), textview);

    GtkWidget *exitButton = gtk_button_new_with_label ("o");
    g_signal_connect(G_OBJECT(exitButton), "clicked", G_CALLBACK(buttonExit), buttonExit);
    gtk_widget_set_name(exitButton, "exitBtn");
    gtk_widget_set_size_request(exitButton, 100, 100);
    gtk_grid_attach (GTK_GRID (grid), exitButton, 2, 5, 1, 2);

    place_and_bind_button("AC", button_exec, numbers+BUTTON_AC, grid, 2, 1, 1, 1);
    place_and_bind_button("/", button_exec, numbers+BUTTON_DIVIS, grid, 3, 1, 1, 1);
    place_and_bind_button("7", button_exec, numbers+BUTTON_SEVEN, grid, 0, 2, 1, 1);
    place_and_bind_button("8", button_exec, numbers+BUTTON_EIGHT, grid, 1, 2, 1, 1);
    place_and_bind_button("9", button_exec, numbers+BUTTON_NINE, grid, 2, 2, 1, 1);
    place_and_bind_button("×", button_exec, numbers+BUTTON_MULTIP, grid, 3, 2, 1, 1);
    place_and_bind_button("4", button_exec, numbers+BUTTON_FOUR, grid, 0, 3, 1, 1);
    place_and_bind_button("5", button_exec, numbers+BUTTON_FIVE, grid, 1, 3, 1, 1);
    place_and_bind_button("6", button_exec, numbers+BUTTON_SIX, grid, 2, 3, 1, 1);
    place_and_bind_button("-", button_exec, numbers+BUTTON_MINUS, grid, 3, 3, 1, 1);
    place_and_bind_button("1", button_exec, numbers+BUTTON_ONE, grid, 0, 4, 1, 1);
    place_and_bind_button("2", button_exec, numbers+BUTTON_TWO, grid, 1, 4, 1, 1);
    place_and_bind_button("3", button_exec, numbers+BUTTON_THREE, grid, 2, 4, 1, 1);
    place_and_bind_button("+", button_exec, numbers+BUTTON_PLUS, grid, 3, 4, 1, 2);
    place_and_bind_button("0", button_exec, numbers+BUTTON_ZERO, grid, 0, 5, 1, 1);
    place_and_bind_button(".", button_exec, numbers+BUTTON_DOT, grid, 1, 5, 1, 1);
    place_and_bind_button("=", button_exec, numbers+BUTTON_EXEC, grid, 2, 5, 1, 1);
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    gtk_init(&argc,&argv);
    cssButtons();
    GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

void cssButtons(void){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen,
                                               GTK_STYLE_PROVIDER(provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    const gchar *cssFile = "css/buttons.css";
    GError *error = 0;

    gtk_css_provider_load_from_file(provider,
                                    g_file_new_for_path(cssFile), &error);
    g_object_unref (provider);
}
