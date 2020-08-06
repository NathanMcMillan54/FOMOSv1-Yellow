#include <gtk/gtk.h>
#include <stdio.h>

int main (int argc, char **argv) {
    printf("Starting FOMOS...");
    gtk_init (&argc, &argv);
    GtkWidget *w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (w), "Hello World!");
    gtk_window_set_default_size (GTK_WINDOW (w), 200, 200);
    g_signal_connect (w, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    gtk_widget_show (w);
    gtk_main ();
    return 0;
}
