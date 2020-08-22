#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void exitSettings() {
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

int openKeyboard (GtkButton *button) {
    system("sh shellScripts/keyboard.sh");
}

// this makes a elctronJs gui open that has all wifi settings
void openWifiSettings (GtkButton *button) {
    system("npm start");
}

void openAbout (GtkButton *button) {
    system("sh shellScripts/openAboutFOMOS.sh");
}

int openDeviceCare () {
    system("sh openDeviceCare.sh");
}

void changeToDarkTheme(GtkButton *button) {
    printf("Adding dark theme to FOMOS... \n");
    system("python3 setDarkTheme.py");
    exitSettings();
}

void changeToLightTheme(GtkButton *button) {
    printf("Adding light theme to FOMOS... \n");
    system("python3 setLightTheme.py");
    exitSettings();
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

void cssButtons(void);
void cssWindow(void);

int main(int argc, char **argv) {
    gtk_init (&argc,&argv);

    cssButtons();
    cssWindow();
    // GUi
    GtkWidget *window;
    GtkWidget *grid;
    // text
    GtkWidget *settings, *softwareSettings, *version, *generalSettings, *wifiSettings, *deviceCareSettings;

    // time
    GtkWidget *timeText = gtk_label_new("Time");
    g_timeout_add (1000, refreshTime, timeText);
    // buttons
    GtkWidget *exitButton, *updateButton, *shutdownBtn, *restartBtn, *keyboardBtn, *wifiSettingsBtn, *deviceCareBtn, *aboutBtn, *darkTheme, *lightTheme;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    settings = gtk_label_new("Settings");
    softwareSettings = gtk_label_new("Software Settings");
    version = gtk_label_new("You using FOMSOv1-Yellow: 1.1");
    exitButton = gtk_button_new_with_label ("o");
    gtk_widget_set_name(exitButton, "exitBtn");
    gtk_widget_set_size_request(exitButton, 100, 100);
    updateButton = gtk_button_new_with_label ("Update");
    gtk_widget_set_name(updateButton, "updateBtn");
    generalSettings = gtk_label_new("General Settings");
    darkTheme = gtk_button_new_with_label("Dark Theme");
    gtk_widget_set_name(darkTheme, "darkThemeBtn");
    lightTheme = gtk_button_new_with_label("Light Theme");
    gtk_widget_set_name(lightTheme, "lightThemeBtn");
    shutdownBtn = gtk_button_new_with_label ("Shutdown");
    gtk_widget_set_name(shutdownBtn, "shutdownBtn");
    restartBtn = gtk_button_new_with_label ("Restart");
    gtk_widget_set_name(restartBtn, "restartBtn");
    keyboardBtn = gtk_button_new_with_label ("Keyboard");
    gtk_widget_set_name(keyboardBtn, "keyboardBtn");
    wifiSettings = gtk_label_new ("Wifi Settings");
    wifiSettingsBtn = gtk_button_new_with_label ("Open Wifi Settings");
    deviceCareSettings = gtk_label_new ("Device Care");
    deviceCareBtn = gtk_button_new_with_label("Open Device Care Settings");
    aboutBtn = gtk_button_new_with_label("About");
    grid = gtk_grid_new ();
    gtk_widget_set_name(window, "window");

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
    gtk_grid_attach (GTK_GRID(grid), shutdownBtn, 0, 6, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), restartBtn, 6, 6, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), keyboardBtn, 12, 6, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), aboutBtn, 0, 7, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), darkTheme, 6, 7, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), lightTheme, 12, 7, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), wifiSettings, 0, 8, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), wifiSettingsBtn, 0, 9, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), deviceCareSettings, 0, 10, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), deviceCareBtn, 0, 11, 6, 1);
    gtk_grid_attach (GTK_GRID(grid), exitButton, 0, 12, 8, 1);

    gtk_widget_show_all (window);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(exitButton), "clicked", G_CALLBACK(exitSettings), exitSettings);
    g_signal_connect(G_OBJECT(updateButton), "clicked", G_CALLBACK(buttonUpdate), buttonUpdate);
    g_signal_connect(G_OBJECT(shutdownBtn), "clicked", G_CALLBACK(shutdownFOMOS), "Shutdown");
    g_signal_connect(G_OBJECT(restartBtn), "clicked", G_CALLBACK(restartFOMOS), "Restart");
    g_signal_connect(G_OBJECT(keyboardBtn), "clicked", G_CALLBACK(openKeyboard), "Keyboard");
    g_signal_connect(G_OBJECT(wifiSettingsBtn), "clicked", G_CALLBACK(openWifiSettings), "Open Wifi Settings");
    g_signal_connect(G_OBJECT(deviceCareBtn), "clicked", G_CALLBACK(openDeviceCare), "Open Device Care Settings");
    g_signal_connect(G_OBJECT(aboutBtn), "clicked", G_CALLBACK(openAbout), "About");
    g_signal_connect(G_OBJECT(darkTheme), "clicked", G_CALLBACK(changeToDarkTheme), "Dark Theme");
    g_signal_connect(G_OBJECT(lightTheme), "clicked", G_CALLBACK(changeToLightTheme), "Light Theme");

    gtk_main();
    return 0;
}

void cssButtons(void){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen,
                                               GTK_STYLE_PROVIDER(provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    const gchar *cssFile = "css/buttons.css";
    GError *error = 0;

    gtk_css_provider_load_from_file(provider,
                                    g_file_new_for_path(cssFile), &error);
    g_object_unref (provider);
}


void cssWindow(void){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen,
                                               GTK_STYLE_PROVIDER(provider),
                                               GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    const gchar *cssFile = "css/windowColor.css";
    GError *error = 0;

    gtk_css_provider_load_from_file(provider,
                                    g_file_new_for_path(cssFile), &error);
    g_object_unref (provider);
}

