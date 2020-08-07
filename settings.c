#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    GtkWidget *window;

    gtk_init (&argc,&argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_window_fullscreen(GTK_WINDOW(window));

    gtk_widget_show_all (window);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}
