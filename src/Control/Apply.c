#include <purescript.h>

PURS_FFI_FUNC_2(Control_Apply_arrayApply, _fs, _xs) {
	const purs_vec_t * fs = purs_any_force_array(_fs);
	const purs_vec_t * xs = purs_any_force_array(_xs);

	purs_vec_t * out = (purs_vec_t *) purs_vec_new();
	purs_vec_reserve(out, fs->length * xs->length);

	int n = 0;
	purs_any_t f;
	for (int i = 0; i < fs->length; i++) {
		f = fs->data[i];
		for (int j = 0; j < xs->length; j++) {
			out->data[n++] = purs_any_app(f, xs->data[j]);
		}
	}
	out->length = n;

	PURS_RC_RELEASE(fs);
	PURS_RC_RELEASE(xs);

	return purs_any_array((const purs_vec_t *) out);
}
