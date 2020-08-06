#include <gtk/gtk.h>
#include <stdio.h>

int main (int argc, char **argv) {
    printf("Starting FOMOS... \n");
    gtk_init (&argc, &argv);
    GtkWidget *w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (w), "FOMOS");
    gtk_window_fullscreen(GTK_WINDOW(w));
    g_signal_connect (w, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    gtk_widget_show (w);
    gtk_main ();
    return 0;
}
