extern crate apps;
use apps::{settings};

extern crate gtk;
use gtk::{prelude::*, Application};

extern crate gio;
use gio::{prelude::*};

extern crate serde_json;

use std::{env::args};

mod gui;

fn main() {
    let application = gtk::Application::new(Some("com.github.NathanMcMillan54.src.main"), Default::default())
        .expect("Initialization failed...");

    application.connect_activate(|app| {
        gui::gui::desktop(app);
    });

    application.run(&args().collect::<Vec<_>>());
}
