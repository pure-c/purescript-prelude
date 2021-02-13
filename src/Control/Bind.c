#include <purescript.h>

PURS_FFI_FUNC_2(Control_Bind_arrayBind, _xs, f) {
	int i;
	purs_any_t tmp;
	const purs_vec_t *xs = purs_any_force_array(_xs);
	if (purs_vec_is_empty(xs)) {
		PURS_RC_RELEASE(xs);
		return purs_any_array_empty;
	}

	purs_vec_t *out = (purs_vec_t *) purs_vec_new();
	purs_vec_foreach(xs, tmp, i) {
		int k;
		purs_any_t tmp2, tmp1;
		tmp1 = purs_any_app(f, tmp);
		const purs_vec_t *v = purs_any_force_array(tmp1);
		PURS_ANY_RELEASE(tmp1);
		purs_vec_foreach(v, tmp2, k) {
			purs_vec_push_mut(out, tmp2);
		}
		PURS_RC_RELEASE(v);
	}
	PURS_RC_RELEASE(xs);
	return purs_any_array((const purs_vec_t *) out);
}
