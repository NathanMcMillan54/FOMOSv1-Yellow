#include <gtk/gtk.h>
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

int showTime() {
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);
    sleep(1);
}

int main(int argc, char **argv) {
    showTime();
    char google[50] = "Google";
    char settings[50] = "Settings";

    GtkWidget *window;
    GtkWidget *settingsButton;
    GtkWidget *googleButton;
    GtkWidget *grid;

    gtk_init (&argc,&argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    grid = gtk_grid_new ();
    settingsButton = gtk_button_new_with_label ("Settings");
    googleButton = gtk_button_new_with_label ("Google");

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

    gtk_main();

    return 0;
}
