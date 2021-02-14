#include <purescript.h>

PURS_FFI_FUNC_2(Data_Eq_refEq, x, y) {
	return purs_any_bool(purs_any_eq(x, y));
}

PURS_FFI_FUNC_3(Data_Eq_eqArrayImpl, f, xs_, ys_) {
	purs_any_t ret;

	const purs_vec_t *xs = purs_any_force_array(xs_);
	const purs_vec_t *ys = purs_any_force_array(ys_);

	if (purs_vec_is_empty(xs) && purs_vec_is_empty(ys)) {
		PURS_RC_RELEASE(xs);
		PURS_RC_RELEASE(ys);
		return purs_any_true;
	} else if (purs_vec_is_empty(xs)) {
		PURS_RC_RELEASE(xs);
		PURS_RC_RELEASE(ys);
		return purs_any_false;
	} else if (purs_vec_is_empty(ys)) {
		PURS_RC_RELEASE(xs);
		PURS_RC_RELEASE(ys);
		return purs_any_false;
	}

	if (purs_vec_length(xs) != purs_vec_length(ys)) {
		ret = purs_any_false;
		goto end;
	} else {
		int i;
		purs_any_t tmp1, tmp2;
		for (i = 0; i < xs->length; i++) {
			tmp1 = purs_any_app(f, xs->data[i]);
			tmp2 = purs_any_app(tmp1, ys->data[i]);
			if (purs_any_eq(tmp2, purs_any_false)) {
				PURS_ANY_RELEASE(tmp2);
				PURS_ANY_RELEASE(tmp1);
				ret = purs_any_false;
				goto end;
			}
			PURS_ANY_RELEASE(tmp2);
			PURS_ANY_RELEASE(tmp1);
		}
		ret = purs_any_true;
		goto end;
	}

end:
	PURS_RC_RELEASE(xs);
	PURS_RC_RELEASE(ys);
	return ret;
}
