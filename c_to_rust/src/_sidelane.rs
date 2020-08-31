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
