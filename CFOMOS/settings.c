#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


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

    // GUi
    GtkWidget *window;
    GtkWidget *timeText = gtk_label_new("Time");
    g_timeout_add (1000, refreshTime, timeText);
    GtkWidget *grid;
    GtkWidget *settings;
    GtkWidget *exitButton;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    settings = gtk_label_new("Settings");
    grid = gtk_grid_new ();

    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_container_add (GTK_LABEL(settings), TRUE);
    gtk_container_add (GTK_LABEL(timeText), TRUE);
    gtk_grid_set_row_spacing (GTK_GRID(grid), 4);
    gtk_grid_set_column_spacing (GTK_GRID(grid), 4);
    gtk_container_add (GTK_CONTAINER(window), grid);

    gtk_grid_attach (GTK_GRID(grid), settings, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), timeText, 4, 0, 4, 4);

    gtk_widget_show_all (window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    gtk_main();
    return 0;
}
