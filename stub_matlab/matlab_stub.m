function matlab_stub
	integer_variable = cast(16,'int32');
	[retstr, retnum] = hop_matlab_to_c('blah', 'world', integer_variable)
end