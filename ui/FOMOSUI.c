#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void buttonSettings (GtkButton *button) {
    system("./ui/settings");
}

void buttonGoogle (GtkButton *button) {
    system("xdg-open http://www.google.com");
}

static gboolean refresh (gpointer user_data) {

    GtkLabel *label = GTK_LABEL (user_data);

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char *currentTime = asctime(timeinfo);

    char *text = g_strdup_printf (currentTime);
    gtk_label_set_label (label, text);
    g_free (text);

    return G_SOURCE_CONTINUE;
}

int main(int argc, char **argv) {
    gtk_init (&argc,&argv);
    char google[50] = "Google";
    char settings[50] = "Settings";

    // GUi
    GtkWidget *window;
    GtkWidget *settingsButton, *googleButton;
    GtkWidget *label = gtk_label_new("Time");
    g_timeout_add (1000, refresh, label);
    GtkWidget *grid;

    GtkCssProvider *provider = gtk_css_provider_new ();
    gtk_css_provider_load_from_path (provider, "ui/FOMOSUI.css", NULL);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    grid = gtk_grid_new ();
    settingsButton = gtk_button_new_with_label (settings);
    googleButton = gtk_button_new_with_label (google);

    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_label_set_selectable (GTK_LABEL(label), TRUE);
    gtk_grid_set_row_spacing (GTK_GRID(grid), 4);
    gtk_grid_set_column_spacing (GTK_GRID(grid), 4);
    gtk_container_add (GTK_CONTAINER(window), grid);

    gtk_grid_attach (GTK_GRID(grid), label, 4, 0, 4, 4);
    gtk_grid_attach (GTK_GRID(grid), settingsButton, 0, 1, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), googleButton, 1, 1, 1, 1);

    gtk_widget_show_all (window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(buttonSettings), settings);
    g_signal_connect(G_OBJECT(googleButton), "clicked", G_CALLBACK(buttonGoogle), google);

    gtk_main();
    return 0;
}
