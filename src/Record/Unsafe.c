#include <purescript.h>

PURS_FFI_FUNC_2(Record_Unsafe_unsafeHas, key_, rec_, {
	const purs_record_t * rec = purs_any_force_record(rec_);
	const purs_str_t * key = purs_any_force_string(key_);
	const purs_any_t * val = purs_record_find_by_key(rec, key->data);
	if (val != NULL) {
		PURS_RC_RELEASE(key);
		PURS_RC_RELEASE(rec);
		return purs_any_true;
	} else {
		PURS_RC_RELEASE(key);
		PURS_RC_RELEASE(rec);
		return purs_any_false;
	}
});

PURS_FFI_FUNC_2(Record_Unsafe_unsafeGet, key_, rec_, {
	const purs_record_t * rec = purs_any_force_record(rec_);
	const purs_str_t * key = purs_any_force_string(key_);
	const purs_any_t * val = purs_record_find_by_key(rec, key->data);
	assert(val != NULL);
	PURS_RC_RELEASE(key);
	PURS_RC_RELEASE(rec);
	PURS_ANY_RETAIN(*val);
	return *val;
});

PURS_FFI_FUNC_3(Record_Unsafe_unsafeSet, key_, value, rec_, {
	const purs_record_t * rec = purs_any_force_record(rec_);
	const purs_str_t * key = purs_any_force_string(key_);
	const purs_any_t out = purs_any_record(purs_record_add(rec, key->data, value));
	PURS_RC_RELEASE(key);
	PURS_RC_RELEASE(rec);
	return out;
});

PURS_FFI_FUNC_2(Record_Unsafe_unsafeDelete, key_, rec_, {
	assert(0); /* todo: implement */

	/* const purs_record_t * rec = purs_any_force_record(rec_); */
	/* const purs_str_t * key = purs_any_force_string(key_); */
	/* const purs_any_t out = purs_any_record(purs_record_remove(rec, key)); */
	/* PURS_RC_RELEASE(key); */
	/* PURS_RC_RELEASE(rec); */
	/* return out; */
});
