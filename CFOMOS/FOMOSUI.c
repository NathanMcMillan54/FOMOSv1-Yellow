#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void openSettings (GtkButton *button) {
    system("./settings");
}

void openGoogle (GtkButton *button) {
    system("xdg-open http://www.google.com");
}

void openCalculator (GtkButton *button) {
    system("./calculator");
}

void shutdownFOMOS (GtkButton *button) {
    system("./shutdown");
}

void restartFOMOS (GtkButton *button) {
    system("./restart");
}

static gboolean refreshTime (gpointer user_data) {

    GtkLabel *timeText = GTK_LABEL (user_data);

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char *currentTime = asctime(timeinfo);

    char *text = g_strdup_printf (currentTime);
    gtk_label_set_label (timeText, text);
    g_free (text);

    return G_SOURCE_CONTINUE;
}


int main(int argc, char **argv) {
    gtk_init (&argc,&argv);
    char google[50] = "Google";
    char settings[50] = "Settings";

    // GUi
    GtkWidget *window;
    GtkWidget *settingsButton, *googleButton, *calculatorButton;
    GtkWidget *shutdownBtn, *restartBtn;
    GtkWidget *timeText = gtk_label_new("Time");
    g_timeout_add (1000, refreshTime, timeText);
    GtkWidget *grid;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    grid = gtk_grid_new ();
    settingsButton = gtk_button_new_with_label (settings);
    gtk_widget_set_name(settingsButton, "css_settingsButton");
    shutdownBtn = gtk_button_new_with_label ("Shutdown");
    gtk_widget_set_name(shutdownBtn, "css_shutdownButton");
    restartBtn = gtk_button_new_with_label ("Restart");
    gtk_widget_set_name(shutdownBtn, "css_restartButton");
    googleButton = gtk_button_new_with_label (google);
    calculatorButton = gtk_button_new_with_label ("Calculator");

    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_label_set_selectable (GTK_LABEL(timeText), TRUE);
    gtk_grid_set_row_spacing (GTK_GRID(grid), 4);
    gtk_grid_set_column_spacing (GTK_GRID(grid), 4);
    gtk_container_add (GTK_CONTAINER(window), grid);

    gtk_grid_attach (GTK_GRID(grid), timeText, 4, 0, 4, 1);
    gtk_grid_attach(GTK_GRID(grid), restartBtn, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), shutdownBtn, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), settingsButton, 0, 1, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), googleButton, 1, 1, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), calculatorButton, 2, 1, 1, 1);

    gtk_widget_show_all (window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(shutdownBtn), "clicked", G_CALLBACK(shutdownFOMOS), "Shutdown");
    g_signal_connect(G_OBJECT(restartBtn), "clicked", G_CALLBACK(restartFOMOS), "Restart");
    g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(openSettings), settings);
    g_signal_connect(G_OBJECT(googleButton), "clicked", G_CALLBACK(openGoogle), google);
    g_signal_connect(G_OBJECT(calculatorButton), "clicked", G_CALLBACK(openCalculator), "Calculator");


    gtk_main();
    return 0;
}
