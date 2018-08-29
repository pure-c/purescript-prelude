#include <stdlib.h>
#include <math.h>
#include "runtime/purescript.h"

#define Data_EuclideanRing_MIN(a,b) (((a)<(b))?(a):(b))

PURS_FFI_FUNC_2(Data_EuclideanRing_intDegree, _x, _y, {
	int x = *purs_any_get_int(_x);
	int y = *purs_any_get_int(_y);
	return PURS_ANY_INT(Data_EuclideanRing_MIN(abs(x), 2147483647));
})

PURS_FFI_FUNC_2(Data_EuclideanRing_intDiv, _x, _y, {
	int x = *purs_any_get_int(_x);
	int y = *purs_any_get_int(_y);
	if (y == 0) {
		return PURS_ANY_INT(0);
	} else {
		if (y > 0) {
			return PURS_ANY_INT(floor((double) x / (double) y));
		} else {
			return PURS_ANY_INT(-(floor((double) x / (double) -y)));
		}
	}
})

PURS_FFI_FUNC_2(Data_EuclideanRing_intMod, _x, _y, {
	int x = *purs_any_get_int(_x);
	int y = *purs_any_get_int(_y);
	if (y == 0) {
		return PURS_ANY_INT(0);
	} else {
		int yy = abs(y);
		return PURS_ANY_INT(((x % yy) + yy) % yy);
	}
})

PURS_FFI_FUNC_2(Data_EuclideanRing_numDiv, _x, _y, {
	float x = *purs_any_get_number(_x);
	float y = *purs_any_get_number(_y);
	return PURS_ANY_NUMBER(x / y);
})
