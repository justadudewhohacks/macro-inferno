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

/* unpack array args */
#define FF_ARG_UNPACK_ARRAY_TO(argN, vec, ffType)	\
	do {																						\
		FF_ARR ff_tmpArr;															\
		FF_ARG_ARRAY(argN, ff_tmpArr)									\
		FF_UNPACK_ARRAY_TO(vec, ff_tmpArr, ffType)		\
	} while (0);

#define FF_ARG_UNPACK_ARRAY(argN, var, type, ffType)	\
	std::vector<type> vec;															\
	FF_ARG_UNPACK_ARRAY_TO(argN, vec, ffType)

#define FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, type, ffType, defaultValue)		\
	std::vector<type> vec;																										\
	if(FF_HAS_ARG(argN)) {																										\
		FF_REQUIRE_ARG_TYPE(argN, ff_array_type, false)													\
		FF_ARG_UNPACK_ARRAY_TO(argN, vec, ffType)																\
	}	else {																																	\
		vec = defaultValue;																											\
	}

#define FF_ARG_UNPACK_BOOL_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, bool, ff_bool)
#define FF_ARG_UNPACK_NUMBER_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, double, ff_number)
#define FF_ARG_UNPACK_UINT_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, uint, ff_uint)
#define FF_ARG_UNPACK_INT_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, int, ff_int)
#define FF_ARG_UNPACK_STRING_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, std::string, ff_string)
#define FF_ARG_UNPACK_ARRAY_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, FF_ARR, ff_array_type)
#define FF_ARG_UNPACK_OBJECT_ARRAY(argN, var) FF_ARG_UNPACK_ARRAY(argN, var, FF_OBJ, ff_obj_type)

#define FF_ARG_UNPACK_BOOL_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, bool, ff_bool, defaultValue)
#define FF_ARG_UNPACK_NUMBER_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, double, ff_number, defaultValue)
#define FF_ARG_UNPACK_UINT_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, uint, ff_uint, defaultValue)
#define FF_ARG_UNPACK_INT_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, int, ff_int, defaultValue)
#define FF_ARG_UNPACK_STRING_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, std::string, ff_string, defaultValue)
#define FF_ARG_UNPACK_ARRAY_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, FF_ARR, ff_array_type, defaultValue)
#define FF_ARG_UNPACK_OBJECT_ARRAY_IFDEF(argN, var, defaultValue) FF_ARG_UNPACK_ARRAY_IFDEF(argN, var, FF_OBJ, ff_obj_type, defaultValue)

#endif