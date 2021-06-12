#![no_std]

#[macro_use] extern crate aarch64_novusk;
pub use aarch64_novusk::boot::init::efi_main;

#[macro_use] extern crate libnu;

pub mod fkmain;
pub mod required;
