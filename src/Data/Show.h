#ifndef Data_Show_FFI_H
#define Data_Show_FFI_H

#include <purescript.h>

PURS_FFI_EXPORT(Data_Show_showIntImpl);
PURS_FFI_EXPORT(Data_Show_showNumberImpl);
PURS_FFI_EXPORT(Data_Show_showCharImpl);
PURS_FFI_EXPORT(Data_Show_showStringImpl);
PURS_FFI_EXPORT(Data_Show_showArrayImpl);
PURS_FFI_EXPORT(Data_Show_cons);
PURS_FFI_EXPORT(Data_Show_join);

#endif // Data_Show_FFI_H
