#include <purescript.h>

PURS_FFI_FUNC_2(Test_Main_testNumberShow, n, _, {
	return purs_any_string(purs_str_new("?"));
});

PURS_FFI_FUNC_1(Test_Main_throwErr, _, {
	assert(0);
});
