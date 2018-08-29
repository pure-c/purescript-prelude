#include <math.h>
#include "runtime/purescript.h"

/* PURS_FFI_VALUE_THUNKED( */
/* 	Data_Bounded_topInt, */
/* 	PURS_ANY_INT_NEW(2147483647)); */

PURS_FFI_VALUE(
	Data_Bounded_topInt,
	PURS_ANY_INT(2147483647));

PURS_FFI_VALUE_THUNKED(
	Data_Bounded_bottomInt,
	PURS_ANY_INT_NEW(-2147483648));

PURS_FFI_VALUE_THUNKED(
	Data_Bounded_topChar,
	PURS_ANY_STRING_NEW_FROM_LIT((char[1]) { 65535 }));

PURS_FFI_VALUE_THUNKED(
	Data_Bounded_bottomChar,
	PURS_ANY_STRING_NEW_FROM_LIT((char[1]) { 0 }));

PURS_FFI_VALUE_THUNKED(
	Data_Bounded_topNumber,
	PURS_ANY_NUMBER_NEW(INFINITY));

PURS_FFI_VALUE_THUNKED(
	Data_Bounded_bottomNumber,
	PURS_ANY_NUMBER_NEW(-INFINITY));
