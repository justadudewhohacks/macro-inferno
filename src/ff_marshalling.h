#include "ff.h"

#ifndef __FF_MARSHALLING_H__
#define __FF_MARSHALLING_H__

#define FF_TYPE(name, type, assertType, castType) \
	FF_##name {																			\
		bool checkType(FF_VAL val) {									\
			return assertType(val);											\
		}																							\
		type cast(FF_VAL val) {												\
			return castType(val);												\
		}																							\
		std::string typeName = std::string(#name);		\
	}

struct FF_TYPE(BOOL, bool, FF_IS_BOOL, FF_CAST_BOOL);
struct FF_TYPE(NUMBER, double, FF_IS_NUMBER, FF_CAST_NUMBER);
struct FF_TYPE(UINT, uint, FF_IS_UINT, FF_CAST_UINT);
struct FF_TYPE(INT, int, FF_IS_INT, FF_CAST_INT);
struct FF_TYPE(STRING, std::string, FF_IS_STRING, FF_TO_STRING);

static FF_BOOL ff_bool = FF_BOOL();
static FF_NUMBER ff_number = FF_NUMBER();
static FF_UINT ff_uint = FF_UINT();
static FF_INT ff_int = FF_INT();
static FF_STRING ff_string = FF_STRING();

#define FF_UNPACK_ARRAY(var, arr, type, ffType) \
	std::vector<type> var;												\
	FF_UNPACK_ARRAY_TO(var, arr, ffType);

#define FF_UNPACK_ARRAY_TO(vec, arr, ffType)																																									\
	for (int i = 0; i < arr->Length(); i++) {																																										\
		FF_VAL ff_val = arr->Get(i);																																															\
		if (!ffType.checkType(ff_val)) {																																													\
			FF_THROW("expected array element to be of type: " + std::string(ffType.typeName) + ", at index: " + std::to_string(i));	\
		}																																																													\
		vec.push_back(ffType.cast(ff_val));																																												\
	}

#define FF_UNPACK_UINT_ARRAY(var, arr) FF_UNPACK_ARRAY(var, arr, uint, ff_uint)
#define FF_UNPACK_INT_ARRAY(var, arr) FF_UNPACK_ARRAY(var, arr, int, ff_int)
#define FF_UNPACK_BOOL_ARRAY(var, arr) FF_UNPACK_ARRAY(var, arr, bool, ff_bool)
#define FF_UNPACK_NUMBER_ARRAY(var, arr) FF_UNPACK_ARRAY(var, arr, double, ff_number)
#define FF_UNPACK_STRING_ARRAY(var, arr) FF_UNPACK_ARRAY(var, arr, std::string, ff_string)

#define FF_UNPACK_UINT_ARRAY_TO(vec, arr) FF_UNPACK_ARRAY_TO(vec, arr, ff_uint)
#define FF_UNPACK_INT_ARRAY_TO(vec, arr) FF_UNPACK_ARRAY_TO(vec, arr, ff_int)
#define FF_UNPACK_BOOL_ARRAY_TO(vec, arr) FF_UNPACK_ARRAY_TO(vec, arr, ff_bool)
#define FF_UNPACK_NUMBER_ARRAY_TO(vec, arr) FF_UNPACK_ARRAY_TO(vec, arr, ff_number)
#define FF_UNPACK_STRING_ARRAY_TO(vec, arr) FF_UNPACK_ARRAY_TO(vec, arr, ff_string)

#endif