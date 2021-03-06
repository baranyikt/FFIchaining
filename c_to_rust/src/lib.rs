#![allow(non_snake_case)]
use std::os::raw::c_char;
use std::ffi::{CString, CStr};

#[no_mangle]
pub extern fn RetrieveString(inp : *mut c_char, depth : *mut i32) -> *mut c_char {
    let c_str: &CStr = unsafe { CStr::from_ptr(inp) };			// construct &CStr slice from inp (*mut c_char)
    let str_slice: &str = c_str.to_str().unwrap();				// construct normal &str slice from &CStr
    let mut str_buf: String = str_slice.to_owned();				// make it a standard owned String to work with, by copying its contents to str_buf
	
	str_buf.push_str(" -- right here in Rust --");				// append Rust-specific part
	
	unsafe {
		if !depth.is_null() {
			*depth += 1;
		}
	}
	
	let result: *mut c_char =
		CString::new(str_buf)									// preparing output: create CString from String, a separately owned copy
		.unwrap()												// can be assumed to be safely unwrapped, since we just created to source (str_buf)
		.into_raw();											// consumes the fresh CString which can be returned to C caller (no destruction made)

	result
}

#[no_mangle]
pub extern fn ReleaseString(inp : *mut c_char) {
	let _c_string: CString = unsafe { CString::from_raw(inp) };	// reintroduce it to the rust ecosystem
	// drop _c_string											// just to drop it silently
}