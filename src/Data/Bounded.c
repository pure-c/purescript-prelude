#include <math.h>
#include <limits.h>
#include <purescript.h>

PURS_FFI_VALUE(
	Data_Bounded_topInt,
	PURS_ANY_INT(INT_MAX));

PURS_FFI_VALUE(
	Data_Bounded_bottomInt,
	PURS_ANY_INT(INT_MIN));

PURS_FFI_VALUE(
	Data_Bounded_topChar,
	PURS_ANY_CHAR(0x10FFFF /* unicode limit */));

PURS_FFI_VALUE(
	Data_Bounded_bottomChar,
	PURS_ANY_CHAR(0));

PURS_FFI_VALUE(
	Data_Bounded_topNumber,
	PURS_ANY_NUM(INFINITY));

PURS_FFI_VALUE(
	Data_Bounded_bottomNumber,
	PURS_ANY_NUM(-INFINITY));
