#include <macro-inferno.h>

class Test_FF_Marshalling {
public:
	static NAN_MODULE_INIT(Init) {
		Nan::SetMethod(target, "unpackBoolArray", unpackBoolArray);
		Nan::SetMethod(target, "unpackNumberArray", unpackNumberArray);
		Nan::SetMethod(target, "unpackIntArray", unpackIntArray);
		Nan::SetMethod(target, "unpackUintArray", unpackUintArray);
		Nan::SetMethod(target, "unpackStringArray", unpackStringArray);

		Nan::SetMethod(target, "unpackAndPackBoolArray", unpackAndPackBoolArray);
		Nan::SetMethod(target, "unpackAndPackNumberArray", unpackAndPackNumberArray);
		Nan::SetMethod(target, "unpackAndPackIntArray", unpackAndPackIntArray);
		Nan::SetMethod(target, "unpackAndPackUintArray", unpackAndPackUintArray);
		Nan::SetMethod(target, "unpackAndPackStringArray", unpackAndPackStringArray);
	}

	static NAN_METHOD(unpackBoolArray) {
		FF_METHOD_CONTEXT("unpackBoolArray");
		FF_UNPACK_BOOL_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
	}

	static NAN_METHOD(unpackNumberArray) {
		FF_METHOD_CONTEXT("unpackNumberArray");
		FF_UNPACK_NUMBER_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
	}

	static NAN_METHOD(unpackIntArray) {
		FF_METHOD_CONTEXT("unpackIntArray");
		FF_UNPACK_INT_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
	}

	static NAN_METHOD(unpackUintArray) {
		FF_METHOD_CONTEXT("unpackUintArray");
		FF_UNPACK_UINT_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
	}

	static NAN_METHOD(unpackStringArray) {
		FF_METHOD_CONTEXT("unpackStringArray");
		FF_UNPACK_STRING_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
	}

	static NAN_METHOD(unpackAndPackBoolArray) {
		FF_METHOD_CONTEXT("unpackAndPackBoolArray");
		FF_UNPACK_BOOL_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
		FF_PACK_ARRAY(ret, vecToUnpackTo);
		FF_RETURN(ret);
	}

	static NAN_METHOD(unpackAndPackNumberArray) {
		FF_METHOD_CONTEXT("unpackAndPackNumberArray");
		FF_UNPACK_NUMBER_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
		FF_PACK_ARRAY(ret, vecToUnpackTo);
		FF_RETURN(ret);
	}

	static NAN_METHOD(unpackAndPackIntArray) {
		FF_METHOD_CONTEXT("unpackAndPackIntArray");
		FF_UNPACK_INT_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
		FF_PACK_ARRAY(ret, vecToUnpackTo);
		FF_RETURN(ret);
	}

	static NAN_METHOD(unpackAndPackUintArray) {
		FF_METHOD_CONTEXT("unpackAndPackUintArray");
		FF_UNPACK_UINT_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
		FF_PACK_ARRAY(ret, vecToUnpackTo);
		FF_RETURN(ret);
	}

	static NAN_METHOD(unpackAndPackStringArray) {
		FF_METHOD_CONTEXT("unpackAndPackStringArray");
		FF_UNPACK_STRING_ARRAY(vecToUnpackTo, FF_CAST_ARRAY(info[0]));
		FF_PACK_STRING_ARRAY(ret, vecToUnpackTo);
		FF_RETURN(ret);
	}
};