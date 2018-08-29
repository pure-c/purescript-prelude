#include "runtime/purescript.h"

PURS_FFI_FUNC_2(Record_Unsafe_unsafeHas, key, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_ = purs_any_get_string(key)->data;
	const purs_record_t * val = purs_record_find_by_key(rec, key_);
	return val != NULL;
})

PURS_FFI_FUNC_2(Record_Unsafe_unsafeGet, key, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_ = purs_any_get_string(key)->data;
	const purs_record_t * val = purs_record_find_by_key(rec, key_);
	if (val != NULL) {
		return val->value;
	} else {
		return (const purs_any_t *) NULL;
	}
})

PURS_FFI_FUNC_3(Record_Unsafe_unsafeSet, key, value, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_copy = purs_string_copy(purs_any_get_string(key)->data);
	return purs_record_add(rec, key_copy, value);
})

PURS_FFI_FUNC_2(Record_Unsafe_unsafeDelete, key, x, {
	const purs_record_t * rec = purs_any_get_record(x);
	const void * key_ = purs_any_get_string(key)->data;
	return PURS_ANY_RECORD_NEW(purs_record_remove(rec, key_));
})
