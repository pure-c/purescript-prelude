#include "runtime/purescript.h"

PURS_FFI_FUNC_1(Data_Show_showIntImpl, x, {
	return PURS_ANY_STRING(
		afmt("%i", * purs_any_get_int(x)));
})

PURS_FFI_FUNC_1(Data_Show_showNumberImpl, x, {
	return PURS_ANY_STRING(
		afmt("%.2f", * purs_any_get_number(x)));
})

// TODO: Implement https://github.com/purescript/purescript-prelude/blob/7a691ce2658bd8eaf28439391e29506dd154fb3d/src/Data/Show.js#L29-L51
PURS_FFI_FUNC_1(Data_Show_showStringImpl, x, {
	return PURS_ANY_STRING(
		afmt("\"%s\"", purs_any_get_string(x)->data));
})

// TODO: Implement https://github.com/purescript-c/purescript-prelude/blob/a878e8d9531cf8c549ef46dfce16988380792cc2/src/Data/Show.js#L12-L27
PURS_FFI_FUNC_1(Data_Show_showCharImpl, x, {
	return PURS_ANY_STRING(
		afmt("'%s'", purs_any_get_string(x)->data));
})

PURS_FFI_FUNC_2(Data_Show_showArrayImpl, f, xs, {
	const purs_vec_t * zs = purs_any_get_array(xs);
	const purs_any_t * tmp;
	const managed_utf8str_t * tmp_s;
	int i;
	char * out = NULL;
	char * tmp_out;
	purs_vec_foreach(zs, tmp, i) {
		tmp_s = purs_any_get_string(purs_any_app(f, tmp));
		tmp_out = out;

		if (i == 0) {
			if (i == zs->length - 1) {
				out = afmt("[%s]", tmp_s->data);
			} else {
				out = afmt("[%s, ", tmp_s->data);
			}
		} else {
			if (i == zs->length - 1) {
				out = afmt("%s%s]", out, tmp_s->data);
			} else {
				out = afmt("%s%s, ", out, tmp_s->data);
			}
		}

		if (tmp_out != NULL) {
			free(tmp_out);
		}
	}

	return PURS_ANY_STRING(out != NULL ? out : afmt("[]"));
})

PURS_FFI_FUNC_2(Data_Show_cons, a, xs, {
	return PURS_ANY_ARRAY(
		purs_vec_insert(purs_any_get_array(xs),
				0,
				a));
})

PURS_FFI_FUNC_2(Data_Show_join, a, xs, {
	const purs_vec_t * zs = purs_any_get_array(xs);
	const char * sep = purs_any_get_string(a)->data;
	const purs_any_t * tmp;
	int i;
	char * out = NULL;
	char * tmp_out;
	purs_vec_foreach(zs, tmp, i) {
		tmp_out = out;
		out = afmt("%s%s%s",
			   out == NULL ? "" : out,
			   out == NULL ? "" : sep,
			   purs_any_get_string(tmp)->data);

		if (tmp_out != NULL) {
			free(tmp_out);
		}
	}
	return PURS_ANY_STRING(out);
})
