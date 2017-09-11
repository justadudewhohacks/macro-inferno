macro-inferno
=============

**A header library with various helpers for native node.js addon development built on top of NAN. Write one-liners for typechecking and converting arguments, unpacking and packing v8::Arrays, unwrapping and wrapping objects and property getters.**

Collapse complex statements into one-liners and avoid writing the same stuff over and over again in each function that your module exposes. Converting JS objects, wrapping and unwrapping instances, packing and unpacking arrays, type checking... , all this can be done using macro-inferno macros, which avoids repetitive and unreadable code and saves you a lot of time that you would spend copy and pasting.

## Why? - Write one-liners instead of massive statements
### Typechecked conversions:
If you care about displaying meaningful error messages to the user of your API, you may end up writing code like this ...
``` c++
NAN_METHOD(aClass::aMethodName) {
  // make sure argument 0 is a string
  if (info.Length() < 1 || !info[0]->IsString()) {
    return Nan::ThrowError(Nan::New(
      "aMethodName - expected arg 0 to be of type: STRING"
    ).ToLocalChecked());
  }
  std::string arg0 = std::string(*Nan::Utf8String(info[0]->ToString()));

  // make sure argument 1 is a number if it was passed
  // otherwise assign a default value
  double arg1;
  if (info.Length() > 1) {
    if (!info[1]->IsNumber()) {
      return Nan::ThrowError(Nan::New(
        "aMethodName - expected arg 0 to be of type: NUMBER"
      ).ToLocalChecked());
    }
    arg1 = info[1]->NumberValue();
  } else {
    arg1 = 0.1;
  }
}
```

Simply write 3 lines of code instead:
``` c++
NAN_METHOD(aClass::aMethodName) {
  FF_METHOD_CONTEXT("aMethodName");
  FF_ARG_STRING(0, std::string arg0);
  FF_ARG_NUMBER_IFDEF(1, double arg1, 0.1);
}
```

### Typechecked conversion of arrays:
Unpacking arrays to std::vector ...
``` c++
NAN_METHOD(aClass::aMethodName) {
  if (info.Length() < 1 || !info[0]->IsArray) {
    return Nan::ThrowError(Nan::New(
      "aMethodName - expected arg 0 to be of type: ARRAY"
    ).ToLocalChecked());
  }
  v8::Local<v8::Array> arr = v8::Local<v8::Array>::Cast(info[0]);

  std::vector<int> intVec;
  for (int i = 0; i < arr->Length(); i++) {
    v8::Local<v8::Value> val = arr->Get(i);
    if (!val->IsInt32()) {
      return Nan::ThrowError(Nan::New(
        "expected array element to be of type: INT, at index: " + std::to_string(i)
      ).ToLocalChecked());
    }
    vec.push_back(info[0]->Int32Value());
  }
}
```

Simply write:
``` c++
NAN_METHOD(aClass::aMethodName) {
  FF_METHOD_CONTEXT("aMethodName");
  FF_ARG_UNPACK_INT_ARRAY(0, intVec);
}
```

## Documentation

### Shortcuts
``` c++
FF_OBJ obj = FF_NEW_OBJ();
v8::Local<v8::Object> obj = Nan::New<v8::Object>();

FF_ARR arr = FF_NEW_ARRAY(10);
v8::Local<v8::Array> arr = Nan::New<v8::Array>(10);

FF_VAL val;
v8::Local<v8::Value> val;

std::string str = FF_NEW_STRING("foo");
std::string str = Nan::New("foo").ToLocalChecked();

FF_RETURN(val);
info.GetReturnValue().Set(val);

bool hasProperty = FF_HAS(obj, "aProperty");
bool hasProperty = Nan::HasOwnProperty(obj, Nan::New("aProperty").ToLocalChecked()).FromJust();
```

### Convert and typecheck native types

#### Required arguments:
Cast argument n to native type or throw a meaningful type error.

``` c++
/* FF_ARG_type(arg number, variable declaration) */

FF_ARG_BOOL(0, bool aBool);
FF_ARG_NUMBER(1, double aNumber);
FF_ARG_UINT(2, uint anUint);
FF_ARG_INT(3, int anInt);
FF_ARG_STRING(4, std::string aString);
FF_ARG_ARRAY(5, FF_ARR anArray);
FF_ARG_OBJ(6, FF_OBJ anObject);
```

For example:
``` c++
NAN_METHOD(aClass::aMethodName) {
  FF_METHOD_CONTEXT("aMethodName");
  FF_ARG_NUMBER(0, double arg);
}
```

invoked like this:
``` javascript
// will not throw
module.aMethodName(0.1);
module.aMethodName(1);
module.aMethodName(-1);

// will throw: aMethodName - expected arg 0 to be of type: NUMBER
module.aMethodName(undefined);
module.aMethodName(null);
module.aMethodName(true);
module.aMethodName('aString');
module.aMethodName([]);
module.aMethodName({});
```

#### Optional arguments:
If defined, cast argument n to native type or throw a meaningful type error, else initialize with default value.

``` c++
/* FF_ARG_type(arg number, variable declaration, default value) */

FF_ARG_BOOL_IFDEF(0, bool aBool, true);
FF_ARG_NUMBER_IFDEF(1, double aNumber, 0.1);
FF_ARG_UINT_IFDEF(2, uint anUint, 1);
FF_ARG_INT_IFDEF(3, int anInt, -1);
FF_ARG_STRING_IFDEF(4, std::string aString, "foo");
FF_ARG_ARRAY_IFDEF(5, FF_ARR anArray, FF_NEW_ARRAY(0));
FF_ARG_OBJ_IFDEF(6, FF_OBJ anObject, FF_NEW_OBJECT())
```

For example:
``` c++
NAN_METHOD(aClass::aMethodName) {
  FF_METHOD_CONTEXT("aMethodName");
  FF_ARG_NUMBER(0, double arg0);
  FF_ARG_NUMBER_IFDEF(1, double arg1, 0.1);
}
```

invoked like this:
``` javascript
// will not throw
module.aMethodName(0.1, 1);
module.aMethodName(0.1, -1);
module.aMethodName(0.1, 0.1);

// will not throw and set arg 1 to the default value
module.aMethodName(0.1);

// will throw: aMethodName - expected arg 1 to be of type: NUMBER
module.aMethodName(0.1, undefined);
module.aMethodName(0.1, null);
module.aMethodName(0.1, true);
module.aMethodName(0.1, 'aString');
module.aMethodName(0.1, []);
module.aMethodName(0.1, {});
```

### Typechecked conversion between arrays and std::vectors
``` c++
// unpack v8::Local<v8::Array> to std::vector<double> vec
FF_ARR someArray = ...
FF_UNPACK_NUMBER_ARRAY(vec, someArray);

// convert numberVec to a v8::Local<v8::Array>
std::vector<double> numberVec = ...
FF_PACK_ARRAY(theNumberArray, numberVec);

// convert stringVec to a v8::Local<v8::Array>
std::vector<std::string> stringVec = ...
FF_PACK_STRING_ARRAY(theStringArray, stringVec);
```