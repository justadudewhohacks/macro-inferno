#include "ff_marshalling.h"

#ifndef __FF_ARGS_H__
#define __FF_ARGS_H__

/* argument checking and casting */

#define FF_HAS_ARG(argN) ( argN < info.Length() )

#define FF_REQUIRE_ARG_TYPE(argN, ff_type, orThrow)																						\
  if (orThrow || !ff_type.checkType(info[argN])) {																						\
    FF_THROW("expected arg " + std::to_string(argN) + " to be of type: " + ff_type.typeName);	\
  }

#define FF_ARG(argN, var, ff_type)											\
  FF_REQUIRE_ARG_TYPE(argN, ff_type, !FF_HAS_ARG(argN))	\
  var = ff_type.cast(info[argN]);

#define FF_ARG_IFDEF(argN, var, ff_type, defaultValue)								\
  if(FF_HAS_ARG(argN)) { FF_REQUIRE_ARG_TYPE(argN, ff_type, false) }	\
  var = (!FF_HAS_ARG(argN) ? defaultValue : ff_type.cast(info[argN]));

#define FF_ARG_INSTANCE(argN, var, ctor, unwrapper)																									\
  if (!FF_HAS_ARG(argN) || !FF_IS_INSTANCE(ctor, info[argN])) {																			\
    FF_THROW("expected arg " + std::to_string(argN) + " to be instance of: " + std::string(#ctor));	\
  }																																																	\
  var = unwrapper(info[argN]->ToObject());

#define FF_ARG_INSTANCE_IFDEF(argN, var, ctor, unwrapper, defaultValue)	\
  var = (!FF_HAS_ARG(argN) || !FF_IS_INSTANCE(ctor, info[argN]) ? defaultValue : unwrapper(info[argN]->ToObject()));

/* aliases */
#define FF_ARG_BOOL(argN, var) FF_ARG(argN, var, ff_bool)
#define FF_ARG_NUMBER(argN, var) FF_ARG(argN, var, ff_number)
#define FF_ARG_UINT(argN, var) FF_ARG(argN, var, ff_uint)
#define FF_ARG_INT(argN, var) FF_ARG(argN, var, ff_int)
#define FF_ARG_STRING(argN, var) FF_ARG(argN, var, ff_string)
#define FF_ARG_ARRAY(argN, var) FF_ARG(argN, var, ff_array_type)
#define FF_ARG_OBJ(argN, var) FF_ARG(argN, var, ff_obj_type)

#define FF_ARG_BOOL_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_bool, defaultValue)
#define FF_ARG_NUMBER_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_number, defaultValue)
#define FF_ARG_UINT_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_uint, defaultValue)
#define FF_ARG_INT_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_int, defaultValue)
#define FF_ARG_STRING_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_string, defaultValue)
#define FF_ARG_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_array_type, defaultValue)
#define FF_ARG_OBJ_IFDEF(argN, var, defaultValue) FF_ARG_IFDEF(argN, var, ff_obj_type, defaultValue)

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
#define FF_GET_OBJ_REQUIRED(obj, var, prop, ctor, unwrapper, clazz)	\
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
#define FF_GET_OBJ_IFDEF(obj, var, prop, ctor, unwrapper, clazz, defaultValue)	\
	if (FF_HAS(obj, prop)) {																											\
		FF_REQUIRE_PROP_INSTANCE(obj, prop, ctor, clazz)														\
	}																																							\
	var = (FF_HAS(obj, prop) ? unwrapper(FF_GET(obj, prop)->ToObject()) : defaultValue);

/* getters - native types */
#define FF_GET_BOOL_REQUIRED(args, var, prop) FF_GET_REQUIRED(args, var, prop, ff_bool)
#define FF_GET_NUMBER_REQUIRED(args, var, prop) FF_GET_REQUIRED(args, var, prop, ff_number)
#define FF_GET_UINT_REQUIRED(args, var, prop) FF_GET_REQUIRED(args, var, prop, ff_uint)
#define FF_GET_INT_REQUIRED(args, var, prop) FF_GET_REQUIRED(args, var, prop, ff_int)
#define FF_GET_STRING_REQUIRED(args, var, prop) FF_GET_REQUIRED(args, var, prop, ff_string)

#define FF_GET_BOOL_IFDEF(args, var, prop, defaultValue) FF_GET_IFDEF(args, var, prop, ff_bool, defaultValue)
#define FF_GET_NUMBER_IFDEF(args, var, prop, defaultValue) FF_GET_IFDEF(args, var, prop, ff_number, defaultValue)
#define FF_GET_UINT_IFDEF(args, var, prop, defaultValue) FF_GET_IFDEF(args, var, prop, ff_uint, defaultValue)
#define FF_GET_INT_IFDEF(args, var, prop, defaultValue) FF_GET_IFDEF(args, var, prop, ff_int, defaultValue)
#define FF_GET_STRING_IFDEF(args, var, prop, defaultValue) FF_GET_IFDEF(args, var, prop, ff_string, defaultValue)

#endif