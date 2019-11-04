#include <purescript.h>

PURS_FFI_FUNC_2(Data_HeytingAlgebra_boolConj, x, y) {
	if (purs_any_get_int(x) && purs_any_get_int(y)) {
		return purs_any_true;
	} else {
		return purs_any_false;
	}
}

PURS_FFI_FUNC_2(Data_HeytingAlgebra_boolDisj, x, y) {
	if (purs_any_get_int(x) || purs_any_get_int(y)) {
		return purs_any_true;
	} else {
		return purs_any_false;
	}
}

PURS_FFI_FUNC_1(Data_HeytingAlgebra_boolNot, x) {
	if (purs_any_get_int(x)) {
		return purs_any_false;
	} else {
		return purs_any_true;
	}
}
