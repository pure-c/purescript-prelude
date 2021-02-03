#include <math.h>
#include <purescript.h>

PURS_FFI_FUNC_1(Data_Show_showIntImpl, x) {
	if (purs_any_is_NaN(x)) {
		return purs_any_string(purs_str_new("%f", NAN));
	}
	return purs_any_string(purs_str_new("%i", purs_any_force_int(x)));
}

PURS_FFI_FUNC_1(Data_Show_showNumberImpl, x) {
	return purs_any_string(purs_str_new("%.2f", purs_any_force_num(x)));
}

// TODO: Implement https://github.com/purescript/purescript-prelude/blob/7a691ce2658bd8eaf28439391e29506dd154fb3d/src/Data/Show.js#L29-L51
PURS_FFI_FUNC_1(Data_Show_showStringImpl, s_) {
	const purs_str_t * s = purs_any_force_string(s_);
	purs_any_t ret = purs_any_string(purs_str_new("\"%s\"", s->data));
	PURS_RC_RELEASE(s);
	return ret;
}

// TODO: Implement https://github.com/purescript-c/purescript-prelude/blob/a878e8d9531cf8c549ef46dfce16988380792cc2/src/Data/Show.js#L12-L27
PURS_FFI_FUNC_1(Data_Show_showCharImpl, x) {
	purs_char_t chr = purs_any_force_char(x);
	size_t bytes = utf8codepointsize(chr);
	char * buf = malloc(bytes + 1);
	utf8catcodepoint(buf, chr, bytes);
	buf[bytes + 1] = '\0';
	purs_any_t out = purs_any_string(purs_str_new("'%s'", buf));
	free(buf);
	return out;
}

static inline purs_any_t showArrayImpl(purs_any_t f, purs_any_t xs_) {
	purs_any_t tmp;
	purs_any_t tmp_r;
	const purs_str_t * tmp_s;
	int i;
	char * out = NULL;
	char * tmp_out;
	const purs_str_t * ret;

	const purs_vec_t * xs = purs_any_force_array(xs_);

	if (xs == NULL) {
		/* todo: could be statically allocated */
		ret = purs_str_new("[]");
		goto end;
	}

	purs_vec_foreach(xs, tmp, i) {
		tmp_r = purs_any_app(f, tmp);
		tmp_s = purs_any_force_string(tmp_r);
		tmp_out = out;

		if (i == 0) {
			if (i == xs->length - 1) {
				out = afmt("[%s]", tmp_s->data);
			} else {
				out = afmt("[%s, ", tmp_s->data);
			}
		} else {
			if (i == xs->length - 1) {
				out = afmt("%s%s]", out, tmp_s->data);
			} else {
				out = afmt("%s%s, ", out, tmp_s->data);
			}
		}

		if (tmp_out != NULL) {
			free(tmp_out);
		}

		PURS_RC_RELEASE(tmp_s);
		PURS_ANY_RELEASE(tmp_r);
	}

	ret = purs_str_new(out);
	free (out);
end:
	PURS_RC_RELEASE(xs);
	return purs_any_string(ret);
}

PURS_FFI_FUNC_2(Data_Show_showArrayImpl, f, xs) {
	return showArrayImpl(f, xs);
}

PURS_FFI_FUNC_2(Data_Show_cons, a, xs) {
	return purs_any_array(
		purs_vec_insert(purs_any_get_array(xs), 0, a));
}

purs_any_t join(purs_any_t sep_, purs_any_t zs_) {
	const purs_vec_t * zs = purs_any_force_array(zs_);
	const purs_str_t * sep = purs_any_force_string(sep_);
	purs_any_t tmp;
	purs_any_t ret;
	int i;
	char * out = NULL;
	char * tmp_out;
	const purs_str_t * tmp_str;

	if (zs->length == 0) {
		ret = purs_any_string(purs_str_new(""));
		goto end;
	}

	purs_vec_foreach(zs, tmp, i) {
		tmp_str = purs_any_force_string(tmp);
		tmp_out = out;
		out = afmt("%s%s%s",
			   out == NULL ? "" : out,
			   out == NULL ? "" : sep->data,
			   tmp_str->data);
		if (tmp_out != NULL) {
			free(tmp_out);
		}
		PURS_RC_RELEASE(tmp_str);
	}

	ret = purs_any_string(purs_str_new(out));

end:
	PURS_RC_RELEASE(zs);
	PURS_RC_RELEASE(sep);
	if (out != NULL) free(out);
	return ret;
}

PURS_FFI_FUNC_2(Data_Show_join, sep_, zs_) {
	return join(sep_, zs_);
}
