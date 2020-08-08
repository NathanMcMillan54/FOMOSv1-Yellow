#include <gtk/gtk.h>
#include <time.h>

static gboolean on_timeout (gpointer user_data) {
    // static unsigned f_times = 0;

    GtkLabel *label = GTK_LABEL (user_data);

    // ++f_times;

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char *currentTime = asctime(timeinfo);

    gchar *text = g_strdup_printf (currentTime);
    gtk_label_set_label (label, text);
    g_free (text);

    return G_SOURCE_CONTINUE; /* or G_SOURCE_REMOVE when you want to stop */
}

int main (int argc, char **argv) {
    gtk_init (&argc, &argv);

    GtkWidget *label = gtk_label_new ("Time");
    g_timeout_add (1000, on_timeout, label);

    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_add (GTK_CONTAINER (window), label);
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    gtk_widget_show_all (window);

    gtk_main ();

    return 0;
}
