#include <purescript.h>

PURS_FFI_FUNC_2(Data_Semigroup_concatString, x, y, {
	return purs_any_concat(x, y);
});

PURS_FFI_FUNC_2(Data_Semigroup_concatArray, x, y, {
	return purs_any_concat(x, y);
});
