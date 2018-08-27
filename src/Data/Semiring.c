#include "runtime/purescript.h"

PURS_FFI_FUNC_2(Data_Semiring_intAdd, x, y, {
	return PURS_ANY_INT(*purs_any_get_int(x) + *purs_any_get_int(y));
})

PURS_FFI_FUNC_2(Data_Semiring_intMul, x, y, {
	return PURS_ANY_INT(*purs_any_get_int(x) * *purs_any_get_int(y));
})

PURS_FFI_FUNC_2(Data_Semiring_numAdd, x, y, {
	return PURS_ANY_NUMBER(*purs_any_get_number(x) * *purs_any_get_number(y));
})

PURS_FFI_FUNC_2(Data_Semiring_numMul, x, y, {
	return PURS_ANY_NUMBER(*purs_any_get_number(x) * *purs_any_get_number(y));
})
