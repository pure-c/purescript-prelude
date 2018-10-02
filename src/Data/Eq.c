#include <purescript.h>

PURS_FFI_FUNC_2(Data_Eq_refEq, x, y, {
	return purs_any_eq(x, y);
});

PURS_FFI_FUNC_3(Data_Eq_eqArrayImpl, f, xs, ys, {
	const purs_vec_t * xs_v = purs_any_get_array(xs);
	const purs_vec_t * ys_v = purs_any_get_array(ys);

	if (xs_v->length != ys_v->length) {
		return purs_any_false;
	} else {
		int i;
		const purs_any_t * tmp;
		purs_vec_foreach(xs_v, tmp, i) {
			if (purs_any_get_int(purs_any_eq(tmp, ys_v->data[i])) == 0) {
				return purs_any_false;
			}
		}
		return purs_any_true;
	}
});
