#include <purescript.h>

PURS_FFI_FUNC_2(Data_HeytingAlgebra_boolConj, x, y) {
	if (purs_any_force_int(x) && purs_any_force_int(y)) {
		return purs_any_true;
	}
	return purs_any_false;
}

PURS_FFI_FUNC_2(Data_HeytingAlgebra_boolDisj, x, y) {
	if (purs_any_force_int(x) || purs_any_force_int(y)) {
		return purs_any_true;
	}
	return purs_any_false;
}

PURS_FFI_FUNC_1(Data_HeytingAlgebra_boolNot, x) {
	if (purs_any_force_int(x)) {
		return purs_any_false;
	}
	return purs_any_true;
}
