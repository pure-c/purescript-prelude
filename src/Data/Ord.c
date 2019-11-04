#include <purescript.h>

static const purs_any_t neg_one = PURS_ANY_INT(-1);
static const purs_any_t pos_one = PURS_ANY_INT(1);
static const purs_any_t zero = PURS_ANY_INT(0);

PURS_FFI_FUNC_3(Data_Ord_ordArrayImpl, f, _xs, _ys) {
	const purs_vec_t * xs = purs_any_force_array(_xs);
	const purs_vec_t * ys = purs_any_force_array(_ys);

	purs_any_t ret;
	purs_any_t o;
	purs_any_t tmp;
	int i = 0;
	int xlen = purs_vec_length(xs);
	int ylen = purs_vec_length(ys);
	purs_any_t x;
	purs_any_t y;

	while (i < xlen && i < ylen) {
		x = xs->data[i];
		y = ys->data[i];
		tmp = purs_any_app(f, x);
		o = purs_any_app(tmp, y);
		PURS_ANY_RELEASE(tmp);
		if (purs_any_get_int(o) != 0) {
			ret = o;
			goto cleanup;
		}
		i++;
	}

	if (xlen == ylen) {
		ret = zero;
		goto cleanup;
	} else if (xlen > ylen) {
		ret = neg_one;
		goto cleanup;
	} else {
		ret = pos_one;
		goto cleanup;
	}

 cleanup:
	PURS_RC_RELEASE(xs);
	PURS_RC_RELEASE(ys);

	return ret;
}
