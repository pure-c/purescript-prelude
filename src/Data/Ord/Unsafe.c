#include "runtime/purescript.h"

PURS_FFI_FUNC_5(Data_Ord_Unsafe_unsafeCompareImpl, lt, eq, gt, _x, _y, {
	const purs_any_t * x = purs_any_unthunk(_x);
	const purs_any_t * y = purs_any_unthunk(_y);

	purs_assert(x->tag == y->tag,
		    "Cannot compare %s with %s",
		    purs_any_tag_str(x->tag),
		    purs_any_tag_str(y->tag));

	switch (x->tag) {
	case PURS_ANY_TAG_INT: {
		purs_any_int_t x_i = *purs_any_get_int(x);
		purs_any_int_t y_i = *purs_any_get_int(y);
		return x_i < y_i ? lt : x_i == y_i ? eq : gt;
	}
	case PURS_ANY_TAG_NUMBER: {
		double x_n = *purs_any_get_number(x);
		double y_n = *purs_any_get_number(y);
		return x_n < y_n ? lt : x_n == y_n ? eq : gt;
	}
	case PURS_ANY_TAG_CHAR: {
		utf8_int32_t x_i = *purs_any_get_char(x);
		utf8_int32_t y_i = *purs_any_get_char(y);
		return x_i < y_i ? lt : x_i == y_i ? eq : gt;
	}
	case PURS_ANY_TAG_STRING: {
		const void * x_utf8 = purs_any_get_string(x)->data;
		const void * y_utf8 = purs_any_get_string(y)->data;
		int result = utf8cmp(x_utf8, y_utf8);
		return result < 0 ? lt : result == 0 ? eq : gt;
	}
	default:
		purs_assert(0, "Cannot compare %s", purs_any_tag_str(x->tag));
	}
})
