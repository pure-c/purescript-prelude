#include <purescript.h>

PURS_FFI_FUNC_5(Data_Ord_Unsafe_unsafeCompareImpl, lt, eq, gt, _x, _y) {
	int x_has_changed = 0;
	int y_has_changed = 0;
	purs_any_t x = purs_any_unthunk(_x, &x_has_changed);
	purs_any_t y = purs_any_unthunk(_y, &y_has_changed);
	purs_any_t ret;

	purs_assert(x.tag == y.tag,
		    "Cannot compare %s with %s",
		    purs_any_tag_str(x.tag),
		    purs_any_tag_str(y.tag));

	switch (x.tag) {
	case PURS_ANY_TAG_INT: {
		purs_int_t x_i = purs_any_get_int(x);
		purs_int_t y_i = purs_any_get_int(y);
		ret = x_i < y_i ? lt : x_i == y_i ? eq : gt;
		goto cleanup;
	}
	case PURS_ANY_TAG_NUM: {
		purs_num_t x_n = purs_any_get_num(x);
		purs_num_t y_n = purs_any_get_num(y);
		ret = x_n < y_n ? lt : x_n == y_n ? eq : gt;
		goto cleanup;
	}
	case PURS_ANY_TAG_CHAR: {
		utf8_int32_t x_i = purs_any_get_char(x);
		utf8_int32_t y_i = purs_any_get_char(y);
		ret = x_i < y_i ? lt : x_i == y_i ? eq : gt;
		goto cleanup;
	}
	case PURS_ANY_TAG_STRING: {
		const purs_str_t * x_str = purs_any_get_string(x);
		const purs_str_t * y_str = purs_any_get_string(y);
		int result = utf8cmp(x_str->data, y_str->data); /* TODO: alias utf8cmp */
		ret = result < 0 ? lt : result == 0 ? eq : gt;
		goto cleanup;
	}
	default:
		purs_assert(0, "Cannot compare %s", purs_any_tag_str(x.tag));
	}

	cleanup:
	if (x_has_changed) PURS_ANY_RELEASE(x);
	if (y_has_changed) PURS_ANY_RELEASE(y);
	return ret;
}
