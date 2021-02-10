#include <purescript.h>

PURS_FFI_FUNC_2(Data_Functor_arrayMap, f, _xs) {
	const purs_vec_t *xs = purs_any_force_array(_xs);

	if (xs == NULL /* empty */) {
		return purs_any_array_empty;
	}

	purs_vec_t *copy = (purs_vec_t *) purs_vec_copy(xs);
	int i;
	purs_any_t tmp;
	purs_vec_foreach(copy, tmp, i) {
		copy->data[i] = purs_any_app(f, tmp);
		PURS_ANY_RELEASE(tmp);
	}
	PURS_RC_RELEASE(xs);
	return purs_any_array((const purs_vec_t *) copy);
}
