#include <stdlib.h>
#include <math.h>
#include <purescript.h>

#define Data_EuclideanRing_MIN(a,b) (((a)<(b))?(a):(b))

PURS_FFI_FUNC_2(Data_EuclideanRing_intDegree, _x, _y, {
	purs_any_int_t x = purs_any_get_int(_x);
	purs_any_int_t y = purs_any_get_int(_y);
	return PURS_ANY_INT_NEW(Data_EuclideanRing_MIN(abs(x), 2147483647));
})

PURS_FFI_FUNC_2(Data_EuclideanRing_intDiv, _x, _y, {
	purs_any_int_t x = purs_any_get_int(_x);
	purs_any_int_t y = purs_any_get_int(_y);
	if (y == 0) {
		return PURS_ANY_INT_NEW(0);
	} else {
		if (y > 0) {
			return PURS_ANY_INT_NEW(floor((double) x / (double) y));
		} else {
			return PURS_ANY_INT_NEW(-(floor((double) x / (double) -y)));
		}
	}
})

PURS_FFI_FUNC_2(Data_EuclideanRing_intMod, _x, _y, {
	purs_any_int_t x = purs_any_get_int(_x);
	purs_any_int_t y = purs_any_get_int(_y);
	if (y == 0) {
		return PURS_ANY_INT_NEW(0);
	} else {
		purs_any_int_t yy = abs(y);
		return PURS_ANY_INT_NEW(((x % yy) + yy) % yy);
	}
})

PURS_FFI_FUNC_2(Data_EuclideanRing_numDiv, _x, _y, {
	double x = purs_any_get_number(_x);
	double y = purs_any_get_number(_y);
	return PURS_ANY_NUMBER_NEW(x / y);
})
