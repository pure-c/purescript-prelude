#include <purescript.h>

PURS_FFI_FUNC_2(Test_Main_testNumberShow, showNumber, _) {
	/* todo: port JS tests  */
	return purs_any_null;
}

PURS_FFI_FUNC_2(Test_Main_throwErr, _str, _) {
	const purs_str_t *s = purs_any_force_string(_str);
	purs_assert(0, "%s", s->data);
	return purs_any_null;
}
