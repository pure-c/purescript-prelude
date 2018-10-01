#include <purescript.h>

PURS_FFI_FUNC_1(Data_Show_showIntImpl, x, {
	return purs_any_string_new(
		afmt("%i", purs_any_get_int(x)));
});

PURS_FFI_FUNC_1(Data_Show_showNumberImpl, x, {
	return purs_any_string_new(
		afmt("%.2f", purs_any_get_num(x)));
});

// TODO: Implement https://github.com/purescript/purescript-prelude/blob/7a691ce2658bd8eaf28439391e29506dd154fb3d/src/Data/Show.js#L29-L51
PURS_FFI_FUNC_1(Data_Show_showStringImpl, x, {
	return purs_any_string_new(
		afmt("\"%s\"", purs_any_get_string(x)));
});

// TODO: Implement https://github.com/purescript-c/purescript-prelude/blob/a878e8d9531cf8c549ef46dfce16988380792cc2/src/Data/Show.js#L12-L27
PURS_FFI_FUNC_1(Data_Show_showCharImpl, x, {
	utf8_int32_t chr = purs_any_get_char(x);
	char * s = 0;
	size_t bytes = utf8codepointsize(chr);
	s = (char *) malloc(bytes + 1);
	utf8catcodepoint(s, chr, bytes);
	s[bytes + 1] = '\0';
	const purs_any_t * out = purs_any_string_new(afmt("'%s'", s));
	free(s);
	return out;
});

PURS_FFI_FUNC_2(Data_Show_showArrayImpl, f, xs, {
	const purs_vec_t * zs = purs_any_get_array(xs);
	const purs_any_t * tmp;
	const purs_any_t * tmp_r;
	const void * tmp_s;
	int i;
	char * out = NULL;
	char * tmp_out;
	purs_vec_foreach(zs, tmp, i) {
		const purs_any_t * tmp_r = purs_any_app(f, tmp);
		tmp_s = purs_any_get_string(tmp_r);
		tmp_out = out;

		if (i == 0) {
			if (i == zs->length - 1) {
				out = afmt("[%s]", tmp_s);
			} else {
				out = afmt("[%s, ", tmp_s);
			}
		} else {
			if (i == zs->length - 1) {
				out = afmt("%s%s]", out, tmp_s);
			} else {
				out = afmt("%s%s, ", out, tmp_s);
			}
		}

		if (tmp_out != NULL) {
			free(tmp_out);
		}
	}

	return purs_any_string_new(out != NULL ? out : afmt("[]"));
});

PURS_FFI_FUNC_2(Data_Show_cons, a, xs, {
	return purs_any_array_new(
		purs_vec_insert(purs_any_get_array(xs), 0, a));
});

PURS_FFI_FUNC_2(Data_Show_join, a, xs, {
	const purs_vec_t * zs = purs_any_get_array(xs);
	const void * sep = purs_any_get_string(a);
	const purs_any_t * tmp;
	int i;
	char * out = NULL;
	char * tmp_out;
	purs_vec_foreach(zs, tmp, i) {
		tmp_out = out;
		out = afmt("%s%s%s",
			   out == NULL ? "" : out,
			   out == NULL ? "" : sep,
			   purs_any_get_string(tmp));

		if (tmp_out != NULL) {
			free(tmp_out);
		}
	}
	return purs_any_string_new(out);
});
