#![no_std]
#![no_main]

#[macro_use] pub extern crate novusk;
pub(crate) use novusk::kernel::printk::printk;

pub mod konfig;

#[no_mangle]
pub extern "C" fn kernel_main() -> ! {

    panic!("Ended");
}

#[no_mangle]
pub extern "C" fn initramfs_main() {

}
