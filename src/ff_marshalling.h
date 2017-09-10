#include "ff.h"

#ifndef __FF_MARSHALLING_H__
#define __FF_MARSHALLING_H__

#define FF_TYPE(name, type, assertType, castType) \
	FF_##name##_TYPE {															\
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
struct FF_TYPE(STRING, std::string, FF_IS_STRING, FF_CAST_STRING);
struct FF_TYPE(ARRAY, FF_ARR, FF_IS_ARRAY, FF_CAST_ARRAY);
struct FF_TYPE(OBJECT, FF_OBJ, FF_IS_OBJ, FF_CAST_OBJ);

static FF_BOOL_TYPE ff_bool = FF_BOOL_TYPE();
static FF_NUMBER_TYPE ff_number = FF_NUMBER_TYPE();
static FF_UINT_TYPE ff_uint = FF_UINT_TYPE();
static FF_INT_TYPE ff_int = FF_INT_TYPE();
static FF_STRING_TYPE ff_string = FF_STRING_TYPE();
static FF_ARRAY_TYPE ff_array_type = FF_ARRAY_TYPE();
static FF_OBJECT_TYPE ff_obj_type = FF_OBJECT_TYPE();

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

#define FF_PACK_ARRAY_(var, vec, create)	\
	FF_ARR var = FF_NEW_ARRAY(vec.size());	\
	for (int i = 0; i < vec.size(); i++) {	\
		var->Set(i, create(vec.at(i)));				\
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

#define FF_IDENTITY_FUNC(arg) arg
#define FF_PACK_ARRAY(var, vec) FF_PACK_ARRAY_(var, vec, Nan::New)
#define FF_PACK_STRING_ARRAY(var, vec) FF_PACK_ARRAY_(var, vec, FF_NEW_STRING)
#define FF_PACK_ARRAY_ARRAY(var, vec) FF_PACK_ARRAY_(var, vec, FF_IDENTITY_FUNC)
#define FF_PACK_OBJ_ARRAY(var, vec) FF_PACK_ARRAY_(var, vec, FF_IDENTITY_FUNC)

#endif