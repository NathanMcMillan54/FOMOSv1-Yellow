#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void buttonExit() {
    exit(0);
}

void buttonUpdate() {
    system("sh osShellScripts/updateCFOMOS.sh");
}

void shutdownFOMOS (GtkButton *button) {
    system("./shutdown");
}

void restartFOMOS (GtkButton *button) {
    system("./restart");
}

void openKeyboard (GtkButton *button) {
    system("sh shellScripts/keyboard.sh");
}

// this makes a elctronJs gui open that has all wifi settings
void openWifiSettings (GtkButton *button) {
    system("npm start");
}

void printDeviceCare() {
    system("sh osShellScripts/diskUsage.sh");
    system("sh osShellScripts/ramUsage.sh");
    system("sh osShellScripts/cpuUsage.sh");
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

    printDeviceCare();

    // GUi
    GtkWidget *window;
    GtkWidget *grid;
    // text
    GtkWidget *settings, *softwareSettings, *version, *generalSettings, *wifiSettings;
    GtkWidget *timeText = gtk_label_new("Time");
    g_timeout_add (1000, refreshTime, timeText);
    // buttons
    GtkWidget *exitButton, *updateButton, *shutdownBtn, *restartBtn, *keyboardBtn, *wifiSettingsBtn;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    settings = gtk_label_new("Settings");
    softwareSettings = gtk_label_new("Software Settings");
    version = gtk_label_new("You are on FOMSOv1-Yellow: 1.1");
    exitButton = gtk_button_new_with_label ("Exit");
    updateButton = gtk_button_new_with_label ("Update");
    generalSettings = gtk_label_new("General Settings");
    shutdownBtn = gtk_button_new_with_label ("Shutdown");
    restartBtn = gtk_button_new_with_label ("Restart");
    keyboardBtn = gtk_button_new_with_label ("Keyboard");
    wifiSettings = gtk_label_new ("Wifi Settings");
    wifiSettingsBtn = gtk_button_new_with_label ("Open Wifi Settings");
    grid = gtk_grid_new ();

    gtk_window_set_title (GTK_WINDOW (window), "Settings");
    gtk_window_fullscreen(GTK_WINDOW(window));
    gtk_container_add (GTK_LABEL(settings), TRUE);
    gtk_container_add (GTK_LABEL(timeText), TRUE);
    gtk_grid_set_row_spacing (GTK_GRID(grid), 12);
    gtk_grid_set_column_spacing (GTK_GRID(grid), 12);
    gtk_container_add (GTK_CONTAINER(window), grid);

    gtk_grid_attach (GTK_GRID(grid), settings, 0, 0, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), timeText, 0, 1, 1, 1);
    gtk_grid_attach (GTK_GRID(grid), softwareSettings, 0, 2, 2, 1);
    gtk_grid_attach (GTK_GRID(grid), version, 0, 3, 3, 1);
    gtk_grid_attach (GTK_GRID(grid), updateButton, 0, 4, 4, 1);
    gtk_grid_attach (GTK_GRID(grid), generalSettings, 0, 5, 5 ,1);
    gtk_grid_attach(GTK_GRID(grid), shutdownBtn, 0, 6, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), restartBtn, 6, 6, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), keyboardBtn, 12, 6, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), wifiSettings, 0, 7, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), wifiSettingsBtn, 0, 8, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), exitButton, 0, 9, 8, 1);

    gtk_widget_show_all (window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(exitButton), "clicked", G_CALLBACK(buttonExit), buttonExit);
    g_signal_connect(G_OBJECT(updateButton), "clicked", G_CALLBACK(buttonUpdate), buttonUpdate);
    g_signal_connect(G_OBJECT(shutdownBtn), "clicked", G_CALLBACK(shutdownFOMOS), "Shutdown");
    g_signal_connect(G_OBJECT(restartBtn), "clicked", G_CALLBACK(restartFOMOS), "Restart");
    g_signal_connect(G_OBJECT(keyboardBtn), "clicked", G_CALLBACK(openKeyboard), "Keyboard");
    g_signal_connect(G_OBJECT(wifiSettingsBtn), "clicked", G_CALLBACK(openWifiSettings), "Open Wifi Settings");

    gtk_main();
    return 0;
}
