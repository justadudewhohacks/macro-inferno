#include <macro-inferno.h>

class Test_FF_Args {
public:
	static NAN_MODULE_INIT(Init) {
		Nan::SetMethod(target, "arg0IsBool", arg0IsBool);
		Nan::SetMethod(target, "arg0IsNumber", arg0IsNumber);
		Nan::SetMethod(target, "arg0IsUint", arg0IsUint);
		Nan::SetMethod(target, "arg0IsInt", arg0IsInt);
		Nan::SetMethod(target, "arg0IsString", arg0IsString);
		Nan::SetMethod(target, "arg0IsArray", arg0IsArray);
		Nan::SetMethod(target, "arg0IsObject", arg0IsObject);

		Nan::SetMethod(target, "arg0IsOptBool", arg0IsOptBool);
		Nan::SetMethod(target, "arg0IsOptNumber", arg0IsOptNumber);
		Nan::SetMethod(target, "arg0IsOptUint", arg0IsOptUint);
		Nan::SetMethod(target, "arg0IsOptInt", arg0IsOptInt);
		Nan::SetMethod(target, "arg0IsOptString", arg0IsOptString);
		Nan::SetMethod(target, "arg0IsOptArray", arg0IsOptArray);
		Nan::SetMethod(target, "arg0IsOptObject", arg0IsOptObject);

		Nan::SetMethod(target, "arg0IsBoolArray", arg0IsBoolArray);
		Nan::SetMethod(target, "arg0IsNumberArray", arg0IsNumberArray);
		Nan::SetMethod(target, "arg0IsUintArray", arg0IsUintArray);
		Nan::SetMethod(target, "arg0IsIntArray", arg0IsIntArray);
		Nan::SetMethod(target, "arg0IsStringArray", arg0IsStringArray);
		Nan::SetMethod(target, "arg0IsArrayArray", arg0IsArrayArray);
		Nan::SetMethod(target, "arg0IsObjectArray", arg0IsObjectArray);

		Nan::SetMethod(target, "arg0IsOptBoolArray", arg0IsOptBoolArray);
	}

	static NAN_METHOD(arg0IsBool) {
		FF_METHOD_CONTEXT("arg0IsBool");
		FF_ARG_BOOL(0, bool arg);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsNumber) {
		FF_METHOD_CONTEXT("arg0IsNumber");
		FF_ARG_NUMBER(0, double arg);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsUint) {
		FF_METHOD_CONTEXT("arg0IsUint");
		FF_ARG_UINT(0, uint arg);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsInt) {
		FF_METHOD_CONTEXT("arg0IsInt");
		FF_ARG_INT(0, int arg);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsString) {
		FF_METHOD_CONTEXT("arg0IsString");
		FF_ARG_STRING(0, std::string arg);
		FF_RETURN(FF_NEW_STRING(arg));
	}

	static NAN_METHOD(arg0IsArray) {
		FF_METHOD_CONTEXT("arg0IsArray");
		FF_ARG_ARRAY(0, FF_ARR arg);
		FF_RETURN(arg);
	}

	static NAN_METHOD(arg0IsObject) {
		FF_METHOD_CONTEXT("arg0IsObject");
		FF_ARG_OBJ(0, FF_OBJ arg);
		FF_RETURN(arg);
	}

	static NAN_METHOD(arg0IsOptBool) {
		FF_METHOD_CONTEXT("arg0IsOptBool");
		FF_ARG_BOOL_IFDEF(0, bool arg, false);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsOptNumber) {
		FF_METHOD_CONTEXT("arg0IsOptNumber");
		FF_ARG_NUMBER_IFDEF(0, double arg, -0.1);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsOptUint) {
		FF_METHOD_CONTEXT("arg0IsOptUint");
		FF_ARG_UINT_IFDEF(0, uint arg, 2);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsOptInt) {
		FF_METHOD_CONTEXT("arg0IsOptInt");
		FF_ARG_INT_IFDEF(0, int arg, -2);
		FF_RETURN(Nan::New(arg));
	}

	static NAN_METHOD(arg0IsOptString) {
		FF_METHOD_CONTEXT("arg0IsOptString");
		FF_ARG_STRING_IFDEF(0, std::string arg, "foo");
		FF_RETURN(FF_NEW_STRING(arg));
	}

	static NAN_METHOD(arg0IsOptArray) {
		FF_METHOD_CONTEXT("arg0IsOptArray");
		FF_ARR arr = FF_NEW_ARRAY(1);
		arr->Set(0, Nan::New(true));
		FF_ARG_ARRAY_IFDEF(0, FF_ARR arg, arr);
		FF_RETURN(arg);
	}

	static NAN_METHOD(arg0IsOptObject) {
		FF_METHOD_CONTEXT("arg0IsOptObject");
		FF_OBJ obj = FF_NEW_OBJ();
		Nan::Set(obj, FF_NEW_STRING("default"), Nan::New(true));
		FF_ARG_OBJ_IFDEF(0, FF_OBJ arg, obj);
		FF_RETURN(arg);
	}

	static NAN_METHOD(arg0IsBoolArray) {
		FF_METHOD_CONTEXT("arg0IsBoolArray");
		FF_ARG_UNPACK_BOOL_ARRAY(0, vec);
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsNumberArray) {
		FF_METHOD_CONTEXT("arg0IsNumberArray");
		FF_ARG_UNPACK_NUMBER_ARRAY(0, vec);
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsUintArray) {
		FF_METHOD_CONTEXT("arg0IsUintArray");
		FF_ARG_UNPACK_UINT_ARRAY(0, vec);
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsIntArray) {
		FF_METHOD_CONTEXT("arg0IsIntArray");
		FF_ARG_UNPACK_INT_ARRAY(0, vec);
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsStringArray) {
		FF_METHOD_CONTEXT("arg0IsStringArray");
		FF_ARG_UNPACK_STRING_ARRAY(0, vec);
		FF_PACK_STRING_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsArrayArray) {
		FF_METHOD_CONTEXT("arg0IsArrayArray");
		FF_ARG_UNPACK_ARRAY_ARRAY(0, vec);
		FF_PACK_ARRAY_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsObjectArray) {
		FF_METHOD_CONTEXT("arg0IsObjectArray");
		FF_ARG_UNPACK_OBJECT_ARRAY(0, vec);
		FF_PACK_OBJ_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptBoolArray) {
		FF_METHOD_CONTEXT("arg0IsOptBoolArray");
		FF_ARG_UNPACK_BOOL_ARRAY_IFDEF(0, vec, std::vector<bool>());
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptNumberArray) {
		FF_METHOD_CONTEXT("arg0IsOptNumberArray");
		FF_ARG_UNPACK_NUMBER_ARRAY_IFDEF(0, vec, std::vector<double>());
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptIntArray) {
		FF_METHOD_CONTEXT("arg0IsOptIntArray");
		FF_ARG_UNPACK_INT_ARRAY_IFDEF(0, vec, std::vector<int>());
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptUintArray) {
		FF_METHOD_CONTEXT("arg0IsOptUintArray");
		FF_ARG_UNPACK_UINT_ARRAY_IFDEF(0, vec, std::vector<uint>());
		FF_PACK_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptStringArray) {
		FF_METHOD_CONTEXT("arg0IsOptStringArray");
		FF_ARG_UNPACK_STRING_ARRAY_IFDEF(0, vec, std::vector<std::string>());
		FF_PACK_STRING_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptArrayArray) {
		FF_METHOD_CONTEXT("arg0IsOptArrayArray");
		FF_ARG_UNPACK_ARRAY_ARRAY_IFDEF(0, vec, std::vector<FF_ARR>());
		FF_PACK_ARRAY_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

	static NAN_METHOD(arg0IsOptObjectArray) {
		FF_METHOD_CONTEXT("arg0IsOptObjectArray");
		FF_ARG_UNPACK_OBJECT_ARRAY_IFDEF(0, vec, std::vector<FF_OBJ>());
		FF_PACK_OBJ_ARRAY(ret, vec);
		FF_RETURN(ret);
	}

};