#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void buttonSettings (GtkButton *button) {
    system("sh settings.sh");
}

void buttonGoogle (GtkButton *button) {
    system("xdg-open http://www.google.com");
}

int main(int argc, char **argv) {
    char google[50] = "Google";
    char settings[50] = "Settings";

    // GUi
    GtkWidget *window;
    GtkWidget *settingsButton;
    GtkWidget *googleButton;
    GtkWidget *grid;

    gtk_init (&argc,&argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    grid = gtk_grid_new ();
    settingsButton = gtk_button_new_with_label (settings);
    googleButton = gtk_button_new_with_label (google);

    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_grid_set_row_spacing (GTK_GRID(grid), 1);
    gtk_grid_set_column_spacing (GTK_GRID(grid), 1);
    gtk_container_add (GTK_CONTAINER(window), grid);

    gtk_grid_attach (GTK_GRID(grid), settingsButton, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), googleButton, 1, 0, 1, 1);

    gtk_widget_show_all (window);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(buttonSettings), settings);
    g_signal_connect(G_OBJECT(googleButton), "clicked", G_CALLBACK(buttonGoogle), google);
    system("sh time.sh");

    gtk_main();
    return 0;
}
