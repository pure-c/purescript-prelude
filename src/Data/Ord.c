#include <purescript.h>

static const purs_any_t neg_one = PURS_ANY_INT(-1);
static const purs_any_t pos_one = PURS_ANY_INT(1);
static const purs_any_t zero = PURS_ANY_INT(0);

PURS_FFI_FUNC_3(Data_Ord_ordArrayImpl, f, _xs, _ys, {
	const purs_vec_t * xs = purs_any_force_array(_xs);
	const purs_vec_t * ys = purs_any_force_array(_ys);

	purs_any_t o;
	int i = 0;
	int xlen = purs_vec_length(xs);
	int ylen = purs_vec_length(ys);
	purs_any_t x;
	purs_any_t y;

	while (i < xlen && i < ylen) {
		x = xs->data[i];
		y = ys->data[i];
		o = purs_any_app(purs_any_app(f, x), y);
		if (purs_any_get_int(o) != 0) {
			return o;
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
});
