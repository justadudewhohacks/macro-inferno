#include "test_ff_args.h"
#include "test_ff_marshalling.h"

void init(v8::Local<v8::Object> target) {
  Test_FF_Args::Init(target);
  Test_FF_Marshalling::Init(target);
};

NODE_MODULE(test, init)

