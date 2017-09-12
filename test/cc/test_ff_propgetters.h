#include <macro-inferno.h>

class Test_FF_PropGetters {
public:
	static NAN_MODULE_INIT(Init) {
		Nan::SetMethod(target, "getAndReturnABoolRequired", getAndReturnABoolRequired);
		Nan::SetMethod(target, "getAndReturnANumberRequired", getAndReturnANumberRequired);
		Nan::SetMethod(target, "getAndReturnAnIntRequired", getAndReturnAnIntRequired);
		Nan::SetMethod(target, "getAndReturnAnUintRequired", getAndReturnAnUintRequired);
		Nan::SetMethod(target, "getAndReturnAStringRequired", getAndReturnAStringRequired);
		Nan::SetMethod(target, "getAndReturnAnArrayRequired", getAndReturnAnArrayRequired);
		Nan::SetMethod(target, "getAndReturnAnObjectRequired", getAndReturnAnObjectRequired);

		Nan::SetMethod(target, "getAndReturnABoolOptional", getAndReturnABoolOptional);
		Nan::SetMethod(target, "getAndReturnANumberOptional", getAndReturnANumberOptional);
		Nan::SetMethod(target, "getAndReturnAnIntOptional", getAndReturnAnIntOptional);
		Nan::SetMethod(target, "getAndReturnAnUintOptional", getAndReturnAnUintOptional);
		Nan::SetMethod(target, "getAndReturnAStringOptional", getAndReturnAStringOptional);
		Nan::SetMethod(target, "getAndReturnAnArrayOptional", getAndReturnAnArrayOptional);
		Nan::SetMethod(target, "getAndReturnAnObjectOptional", getAndReturnAnObjectOptional);

		Nan::SetMethod(target, "getUnpackAndReturnBoolArray", getUnpackAndReturnBoolArray);
		Nan::SetMethod(target, "getUnpackAndReturnNumberArray", getUnpackAndReturnNumberArray);
		Nan::SetMethod(target, "getUnpackAndReturnIntArray", getUnpackAndReturnIntArray);
		Nan::SetMethod(target, "getUnpackAndReturnUintArray", getUnpackAndReturnUintArray);
		Nan::SetMethod(target, "getUnpackAndReturnStringArray", getUnpackAndReturnStringArray);
		Nan::SetMethod(target, "getUnpackAndReturnArrayArray", getUnpackAndReturnArrayArray);
		Nan::SetMethod(target, "getUnpackAndReturnObjectArray", getUnpackAndReturnObjectArray); 

		Nan::SetMethod(target, "getUnpackAndReturnOptBoolArray", getUnpackAndReturnOptBoolArray);
		Nan::SetMethod(target, "getUnpackAndReturnOptNumberArray", getUnpackAndReturnOptNumberArray);
		Nan::SetMethod(target, "getUnpackAndReturnOptIntArray", getUnpackAndReturnOptIntArray);
		Nan::SetMethod(target, "getUnpackAndReturnOptUintArray", getUnpackAndReturnOptUintArray);
		Nan::SetMethod(target, "getUnpackAndReturnOptStringArray", getUnpackAndReturnOptStringArray);
		Nan::SetMethod(target, "getUnpackAndReturnOptArrayArray", getUnpackAndReturnOptArrayArray);
		Nan::SetMethod(target, "getUnpackAndReturnOptObjectArray", getUnpackAndReturnOptObjectArray);
	}

	static NAN_METHOD(getAndReturnABoolRequired) {
		FF_METHOD_CONTEXT("getAndReturnABoolRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_BOOL_REQUIRED(argObj, bool aBool, "aBool");
		FF_RETURN(Nan::New(aBool));
	}

	static NAN_METHOD(getAndReturnANumberRequired) {
		FF_METHOD_CONTEXT("getAndReturnANumberRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_NUMBER_REQUIRED(argObj, double aNumber, "aNumber");
		FF_RETURN(Nan::New(aNumber));
	}

	static NAN_METHOD(getAndReturnAnIntRequired) {
		FF_METHOD_CONTEXT("getAndReturnAnIntRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_INT_REQUIRED(argObj, int anInt, "anInt");
		FF_RETURN(Nan::New(anInt));
	}

	static NAN_METHOD(getAndReturnAnUintRequired) {
		FF_METHOD_CONTEXT("getAndReturnAnUintRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UINT_REQUIRED(argObj, uint anUint, "anUint");
		FF_RETURN(Nan::New(anUint));
	}

	static NAN_METHOD(getAndReturnAStringRequired) {
		FF_METHOD_CONTEXT("getAndReturnAStringRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_STRING_REQUIRED(argObj, std::string aString, "aString");
		FF_RETURN(FF_NEW_STRING(aString));
	}

	static NAN_METHOD(getAndReturnAnArrayRequired) {
		FF_METHOD_CONTEXT("getAndReturnAnArrayRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_ARRAY_REQUIRED(argObj, FF_ARR anArray, "anArray");
		FF_RETURN(anArray);
	}

	static NAN_METHOD(getAndReturnAnObjectRequired) {
		FF_METHOD_CONTEXT("getAndReturnAnObjectRequired");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_OBJ_REQUIRED(argObj, FF_OBJ anObject, "anObject");
		FF_RETURN(anObject);
	}

	static NAN_METHOD(getAndReturnABoolOptional) {
		FF_METHOD_CONTEXT("getAndReturnABoolOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_BOOL_IFDEF(argObj, bool aBool, "aBool", false);
		FF_RETURN(Nan::New(aBool));
	}

	static NAN_METHOD(getAndReturnANumberOptional) {
		FF_METHOD_CONTEXT("getAndReturnANumberOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_NUMBER_IFDEF(argObj, double aNumber, "aNumber", -0.1);
		FF_RETURN(Nan::New(aNumber));
	}

	static NAN_METHOD(getAndReturnAnIntOptional) {
		FF_METHOD_CONTEXT("getAndReturnAnIntOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_INT_IFDEF(argObj, int anInt, "anInt", -2);
		FF_RETURN(Nan::New(anInt));
	}

	static NAN_METHOD(getAndReturnAnUintOptional) {
		FF_METHOD_CONTEXT("getAndReturnAnUintOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UINT_IFDEF(argObj, uint anUint, "anUint", 2);
		FF_RETURN(Nan::New(anUint));
	}

	static NAN_METHOD(getAndReturnAStringOptional) {
		FF_METHOD_CONTEXT("getAndReturnAStringOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_STRING_IFDEF(argObj, std::string aString, "aString", "foo");
		FF_RETURN(FF_NEW_STRING(aString));
	}

	static NAN_METHOD(getAndReturnAnArrayOptional) {
		FF_METHOD_CONTEXT("getAndReturnAnArrayOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_ARR defaultArr = FF_NEW_ARRAY(1);
		defaultArr->Set(0, Nan::New(true));
		FF_GET_ARRAY_IFDEF(argObj, FF_ARR anArray, "anArray", defaultArr);
		FF_RETURN(anArray);
	}

	static NAN_METHOD(getAndReturnAnObjectOptional) {
		FF_METHOD_CONTEXT("getAndReturnAnObjectOptional");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_OBJ defaultObj = FF_NEW_OBJ();
		Nan::Set(defaultObj, FF_NEW_STRING("default"), Nan::New(true));
		FF_GET_OBJ_IFDEF(argObj, FF_OBJ anObject, "anObject", defaultObj);
		FF_RETURN(anObject);
	}

	static NAN_METHOD(getUnpackAndReturnBoolArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnBoolArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_BOOL_ARRAY(argObj, vecToUnpackTo, "boolArray");
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnNumberArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnNumberArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_NUMBER_ARRAY(argObj, vecToUnpackTo, "numberArray");
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnUintArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnUintArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_UINT_ARRAY(argObj, vecToUnpackTo, "uintArray");
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnIntArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnIntArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_INT_ARRAY(argObj, vecToUnpackTo, "intArray");
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnStringArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnStringArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_STRING_ARRAY(argObj, vecToUnpackTo, "stringArray");
		FF_PACK_STRING_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnArrayArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnArrayArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_ARRAY_ARRAY(argObj, vecToUnpackTo, "arrayArray");
		FF_PACK_ARRAY_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnObjectArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnObjectArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		FF_GET_UNPACK_OBJECT_ARRAY(argObj, vecToUnpackTo, "objectArray");
		FF_PACK_OBJ_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptBoolArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptBoolArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<bool> defaultVec;
		defaultVec.push_back(false);
		FF_GET_UNPACK_BOOL_ARRAY_IFDEF(argObj, vecToUnpackTo, "boolArray", defaultVec);
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptNumberArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptNumberArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<double> defaultVec;
		defaultVec.push_back(-0.1);
		FF_GET_UNPACK_NUMBER_ARRAY_IFDEF(argObj, vecToUnpackTo, "numberArray", defaultVec);
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptIntArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptIntArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<int> defaultVec;
		defaultVec.push_back(-2);
		FF_GET_UNPACK_INT_ARRAY_IFDEF(argObj, vecToUnpackTo, "intArray", defaultVec);
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptUintArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptUintArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<uint> defaultVec;
		defaultVec.push_back(2);
		FF_GET_UNPACK_UINT_ARRAY_IFDEF(argObj, vecToUnpackTo, "uintArray", defaultVec);
		FF_PACK_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptStringArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptStringArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<std::string> defaultVec;
		defaultVec.push_back("foo");
		FF_GET_UNPACK_STRING_ARRAY_IFDEF(argObj, vecToUnpackTo, "stringArray", defaultVec);
		FF_PACK_STRING_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptArrayArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptArrayArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<FF_ARR> defaultVec;
		defaultVec.push_back(FF_NEW_ARRAY(0));
		FF_GET_UNPACK_ARRAY_ARRAY_IFDEF(argObj, vecToUnpackTo, "arrayArray", defaultVec);
		FF_PACK_ARRAY_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}

	static NAN_METHOD(getUnpackAndReturnOptObjectArray) {
		FF_METHOD_CONTEXT("getUnpackAndReturnOptObjectArray");
		FF_ARG_OBJ(0, FF_OBJ argObj);
		std::vector<FF_OBJ> defaultVec;
		defaultVec.push_back(FF_NEW_OBJ());
		FF_GET_UNPACK_OBJECT_ARRAY_IFDEF(argObj, vecToUnpackTo, "objectArray", defaultVec);
		FF_PACK_OBJ_ARRAY(retArray, vecToUnpackTo);
		FF_RETURN(retArray);
	}
};