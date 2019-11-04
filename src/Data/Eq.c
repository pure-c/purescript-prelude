#include <purescript.h>

PURS_FFI_FUNC_2(Data_Eq_refEq, x, y) {
	return purs_any_bool(purs_any_eq(x, y));
}

PURS_FFI_FUNC_3(Data_Eq_eqArrayImpl, f, xs_, ys_) {
	purs_any_t ret;
	const purs_vec_t * xs = purs_any_force_array(xs_);
	const purs_vec_t * ys = purs_any_force_array(ys_);

	if (purs_vec_length(xs) != purs_vec_length(ys)) {
		ret = purs_any_false;
		goto end;
	} else {
		int i;
		purs_any_t tmp;
		purs_any_t tmp_f;
		purs_vec_foreach(xs, tmp, i) {
			tmp_f = purs_any_app(f, tmp);
			if (purs_any_is_false(purs_any_app(tmp_f,
							   ys->data[i]))) {
				PURS_ANY_RELEASE(tmp_f);
				return purs_any_false;
			}
			PURS_ANY_RELEASE(tmp_f);
		}
		ret = purs_any_true;
		goto end;
	}

end:
	PURS_RC_RELEASE(xs);
	PURS_RC_RELEASE(ys);
	return ret;
}
