#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

void buttonExit() {
    exit(0);
}

int main(int argc, char **argv) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *text;
    GtkWidget *exitButton;

    gtk_init(&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    text = gtk_label_new("Settings");
    grid = gtk_grid_new();
    exitButton = gtk_button_new_with_label ("Exit");

    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_label_set_selectable (GTK_LABEL(text), TRUE);
    gtk_grid_set_row_spacing (GTK_GRID(grid), 4);
    gtk_grid_set_column_spacing (GTK_GRID(grid), 4);
    gtk_container_add (GTK_CONTAINER(window), grid);

    gtk_grid_attach (GTK_GRID(grid), text, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), exitButton, 0, 2, 2, 1);

    gtk_widget_show_all (window);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(exitButton), "clicked", G_CALLBACK(buttonExit), buttonExit);

    gtk_main();

    return 0;
}
