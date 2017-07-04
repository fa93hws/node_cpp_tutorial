#include <node.h>
#include <vector>
#include "./wrapper.h"

using v8::Local;
using v8::Object;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Number;
using v8::Value;

void method(const FunctionCallbackInfo<Value>& args){
    Isolate* isolate = args.GetIsolate();
    Demo_lib demo = Demo_lib();
    std::vector<int> out;
    demo.getPrimUnder(12345,out);
    int num = out.size();
    args.GetReturnValue().Set(Number::New(isolate, num));
}

void InitAll(Local<Object> exports) {
//   Wrapper::Init(exports);
    NODE_SET_METHOD(exports, "getPrimeUnder", method);
}

NODE_MODULE(test, InitAll)