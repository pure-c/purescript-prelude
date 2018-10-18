#include <purescript.h>

PURS_FFI_FUNC_2(Data_Semiring_intAdd, x, y, {
	return purs_any_int_new(purs_any_get_int(x) + purs_any_get_int(y));
});

PURS_FFI_FUNC_2(Data_Semiring_intMul, x, y, {
	return purs_any_int_new(purs_any_get_int(x) * purs_any_get_int(y));
});

PURS_FFI_FUNC_2(Data_Semiring_numAdd, x, y, {
	return purs_any_num_new(purs_any_get_num(x) + purs_any_get_num(y));
});

PURS_FFI_FUNC_2(Data_Semiring_numMul, x, y, {
	return purs_any_num_new(purs_any_get_num(x) * purs_any_get_num(y));
});
