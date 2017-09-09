#include "ff_marshalling.h"

#ifndef __FF_PROPGETTERS_H__
#define __FF_PROPGETTERS_H__

/* js property getters */

#define FF_GET(obj, prop) Nan::Get(obj, FF_NEW_STRING(prop)).ToLocalChecked()

#define FF_REQUIRE_PROP(obj, prop)														\
	if (!FF_HAS(obj, prop)) {																		\
		FF_THROW("object has no property: " + std::string(prop)); \
	}

#define FF_REQUIRE_PROP_TYPE(obj, prop, ff_type)																								\
	if (!ff_type.checkType(FF_GET(obj, prop))) {																									\
		FF_THROW("expected property: " + std::string(prop) + " to be of type: " + ff_type.typeName);\
	}

#define FF_REQUIRE_PROP_INSTANCE(obj, prop, ctor, clazz)																								\
	if (!FF_IS_INSTANCE(ctor, FF_GET(obj, prop))) {																												\
    FF_THROW("expected property: " + std::string(prop) + " to be instance of: " + std::string(#clazz));	\
  }

/* get js prop, throw if undefined or invalid type */
#define FF_GET_REQUIRED(obj, var, prop, ff_type)	\
	FF_REQUIRE_PROP(obj, prop)											\
	FF_REQUIRE_PROP_TYPE(obj, prop, ff_type)				\
	var = ff_type.cast(FF_GET(obj, prop));

/* unpack object, throw if undefined or not instance */
#define FF_GET_INSTANCE_REQUIRED(obj, var, prop, ctor, unwrapper, clazz)	\
	FF_REQUIRE_PROP(obj, prop)																				\
	FF_REQUIRE_PROP_INSTANCE(obj, prop, ctor, clazz)									\
	var = unwrapper(obj);

/* get js prop if defined, throw if invalid type */
#define FF_GET_IFDEF(obj, var, prop, ff_type, defaultValue)										\
	if (FF_HAS(obj, prop)) {																										\
		FF_REQUIRE_PROP_TYPE(obj, prop, ff_type)																	\
	}																																						\
	var = (FF_HAS(obj, prop) ? ff_type.cast(FF_GET(obj, prop)) : defaultValue);

/* unpack object if defined if not instance */
#define FF_GET_INSTANCE_IFDEF(obj, var, prop, ctor, unwrapper, clazz, defaultValue)	\
	if (FF_HAS(obj, prop)) {																													\
		FF_REQUIRE_PROP_INSTANCE(obj, prop, ctor, clazz)																\
	}																																									\
	var = (FF_HAS(obj, prop) ? unwrapper(FF_GET(obj, prop)->ToObject()) : defaultValue);

/* getters - native types */
#define FF_GET_BOOL_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_bool)
#define FF_GET_NUMBER_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_number)
#define FF_GET_UINT_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_uint)
#define FF_GET_INT_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_int)
#define FF_GET_STRING_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_string)
#define FF_GET_ARRAY_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_array_type)
#define FF_GET_OBJ_REQUIRED(obj, var, prop) FF_GET_REQUIRED(obj, var, prop, ff_obj_type)

#define FF_GET_BOOL_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_bool, defaultValue)
#define FF_GET_NUMBER_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_number, defaultValue)
#define FF_GET_UINT_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_uint, defaultValue)
#define FF_GET_INT_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_int, defaultValue)
#define FF_GET_STRING_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_string, defaultValue)
#define FF_GET_ARRAY_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_array_type, defaultValue)
#define FF_GET_OBJ_IFDEF(obj, var, prop, defaultValue) FF_GET_IFDEF(obj, var, prop, ff_obj_type, defaultValue)

#endif