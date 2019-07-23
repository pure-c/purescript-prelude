#include <purescript.h>

PURS_FFI_FUNC_2(Data_Ring_intSub, x, y, {
	return purs_any_int(purs_any_get_int(x) - purs_any_get_int(y));
});

PURS_FFI_FUNC_2(Data_Ring_numSub, x, y, {
	return purs_any_num(purs_any_get_num(x) - purs_any_get_num(y));
});
