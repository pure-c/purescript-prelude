#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <purescript.h>

#define Data_EuclideanRing_MIN(a,b) (((a)<(b))?(a):(b))

PURS_FFI_FUNC_1(Data_EuclideanRing_intDegree, _x, {
	purs_any_int_t x = purs_any_force_int(_x);
	return purs_any_int(Data_EuclideanRing_MIN(labs(x), INT_MAX));
});

PURS_FFI_FUNC_2(Data_EuclideanRing_intDiv, _x, _y, {
	purs_any_int_t x = purs_any_force_int(_x);
	purs_any_int_t y = purs_any_force_int(_y);
	if (y == 0) {
		return purs_any_int(0);
	} else {
		if (y > 0) {
			return purs_any_int(floor((double) x / (double) y));
		} else {
			return purs_any_int(-(floor((double) x / (double) -y)));
		}
	}
});

PURS_FFI_FUNC_2(Data_EuclideanRing_intMod, _x, _y, {
	purs_any_int_t x = purs_any_force_int(_x);
	purs_any_int_t y = purs_any_force_int(_y);
	if (y == 0) {
		return purs_any_int(0);
	} else {
		purs_any_int_t yy = abs(y);
		return purs_any_int(((x % yy) + yy) % yy);
	}
});

PURS_FFI_FUNC_2(Data_EuclideanRing_numDiv, _x, _y, {
	double x = purs_any_force_num(_x);
	double y = purs_any_force_num(_y);
	return purs_any_num(x / y);
});
