#include <purescript.h>

PURS_FFI_FUNC_2(Data_Functor_arrayMap, f, _xs, {
	const purs_vec_t * xs = purs_any_get_array(_xs);
	purs_vec_t * copy = (purs_vec_t *) purs_vec_copy(xs);
	int i;
	purs_any_t tmp;
	purs_vec_foreach(copy, tmp, i) {
		copy->data[i] = purs_any_app(f, tmp);
	}
	return purs_any_array((const purs_vec_t *) copy);
});
