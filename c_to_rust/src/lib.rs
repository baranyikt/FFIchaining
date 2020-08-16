use std::os::raw::c_char;
use std::ffi::{CString, CStr};
use std::mem::transmute;

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
/*
pub fn manipulator_caller() {
    let mut v1 = 32;
	let mut v2_pre = "hello".to_string();
	unsafe {
		let v2: *mut u8 = &mut v2_pre.as_bytes_mut()[0];
		manipulator(&mut v1,v2);
	}
}

pub extern "C" fn manipulator(i : &mut i32, _cs : *mut u8) {
    *i = *i + 1;
}
*/

#[allow(non_snake_case)]
pub extern "C" fn RetrieveString(inp : *mut c_char, depth : *mut i32) -> *mut c_char {

    let c_str: &CStr = unsafe { CStr::from_ptr(inp) };			// construct &CStr slice from inp (*mut c_char)
    let str_slice: &str = c_str.to_str().unwrap();				// construct normal &str slice from &CStr
    let mut str_buf: String = str_slice.to_owned();				// make it a standard owned String to work with, by copying its contents to str_buf
	
	str_buf.push_str("-- right here in Rust --");				// append Rust-specific part
	
	unsafe {
		if !depth.is_null() {
			*depth += 1;
		}
	}
	
	let result = unsafe {
		transmute(
			CString::new(str_buf).unwrap()						// preparing output: create CString from String, a separately owned copy
			.as_ptr()											// use CStr::as_ptr through CString::Deref<Target = CStr>
		)														// transmute converts it to "non-owned" pure *mut c_char
		};	result
}

#[allow(non_snake_case)]
pub extern "C" fn ReleaseString(inp : *mut c_char) {
	let _c_string: CString = unsafe { CString::from_raw(inp) };	// reintroduce it to the rust ecosystem
	// drop _c_string											// just to drop it silently
}