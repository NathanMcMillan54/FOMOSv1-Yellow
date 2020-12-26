use gtk::{prelude::*, Application, Button};

pub fn desktop(application: &Application) {
    let window = gtk::ApplicationWindow::new(application);

    window.set_title("2.5.3");
    window.set_border_width(10);
    window.set_position(gtk::WindowPosition::Center);
    window.fullscreen();

    window.show_all();
}