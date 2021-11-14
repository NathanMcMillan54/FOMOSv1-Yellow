pub(crate) const KONFIG: &str = include_str!("konfig.txt");

#[no_mangle]
pub extern "C" fn kernel_config() -> &'static str {
    return KONFIG;
}