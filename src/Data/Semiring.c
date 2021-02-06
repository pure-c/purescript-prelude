#include <purescript.h>

PURS_FFI_FUNC_2(Data_Semiring_intAdd, x, y) {
	return purs_any_int(purs_any_force_int(x) + purs_any_force_int(y));
}

PURS_FFI_FUNC_2(Data_Semiring_intMul, x, y) {
	return purs_any_int(purs_any_force_int(x) * purs_any_force_int(y));
}

PURS_FFI_FUNC_2(Data_Semiring_numAdd, x, y) {
	return purs_any_num(purs_any_force_num(x) + purs_any_force_num(y));
}

PURS_FFI_FUNC_2(Data_Semiring_numMul, x, y) {
	return purs_any_num(purs_any_force_num(x) * purs_any_force_num(y));
}
