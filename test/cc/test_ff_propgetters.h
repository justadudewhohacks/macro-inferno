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
};