#include "test_ff_args.h"

void init(v8::Local<v8::Object> target) {
  Test_FF_Args::Init(target);
};

NODE_MODULE(test, init)

