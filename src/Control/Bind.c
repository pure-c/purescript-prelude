#include <purescript.h>

PURS_FFI_FUNC_2(Control_Bind_arrayBind, _xs, f, {
	int i;
	purs_any_t tmp;
	const purs_vec_t * xs = purs_any_get_array(_xs);
	purs_vec_t * out = (purs_vec_t *) purs_vec_new();
	purs_vec_foreach(xs, tmp, i) {
		int k;
		purs_any_t tmp_2;
		const purs_vec_t * v = purs_any_get_array(purs_any_app(f, tmp));
		purs_vec_foreach(v, tmp_2, k) {
			purs_vec_push_mut(out, tmp_2);
		}
	}
	return purs_any_array((const purs_vec_t *) out);
});
