#include "runtime/purescript.h"

PURS_ANY_THUNK_DEF(neg_one, PURS_ANY_INT(-1));
PURS_ANY_THUNK_DEF(zero, PURS_ANY_INT(0));
PURS_ANY_THUNK_DEF(pos_one, PURS_ANY_INT(1));

PURS_FFI_FUNC_3(Data_Ord_ordArrayImpl, f, _xs, _ys, {
	const purs_vec_t * xs = purs_any_get_array(_xs);
	const purs_vec_t * ys = purs_any_get_array(_ys);
	int o;
	int i = 0;
	int xlen = xs->length;
	int ylen = ys->length;
	const purs_any_t * x;
	const purs_any_t * y;

	while (i < xlen && i < ylen) {
		x = xs->data[i];
		y = ys->data[i];
		o = *purs_any_get_int(purs_any_app(purs_any_app(f, x), y));
		if (o != 0) {
			return zero;
		}
		i++;
	}

	if (xlen == ylen) {
		return zero;
	} else if (xlen > ylen) {
		return neg_one;
	} else {
		return pos_one;
	}
})
