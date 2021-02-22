#include "Data.Symbol.h"

PURS_FFI_FUNC_1(Data_Symbol_unsafeCoerce, arg) {
	PURS_ANY_RETAIN(arg);
	return arg;
}
