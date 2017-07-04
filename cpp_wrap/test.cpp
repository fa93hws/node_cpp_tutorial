#include <node.h>
#include <vector>
#include "../cpp/demo_lib.h"
#include <ctime>

using v8::Local;
using v8::Object;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Number;
using v8::Value;
using v8::Function;

void method(const FunctionCallbackInfo<Value>& args){
    Isolate* isolate = args.GetIsolate();
    // get input 
    double limit = args[0]->NumberValue();
    // get callback
    Local<Function> cb = Local<Function>::Cast(args[1]);
    // calculate
    Demo_lib demo = Demo_lib();
    std::vector<int> out;
    clock_t begin = clock();
    demo.getPrimUnder(limit,out);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    int num = out.size();
    // callback
    Local<Value> argv[2] = { Number::New(isolate, num), Number::New(isolate,elapsed_secs) };
    cb -> Call(Null(isolate),2,argv);
    // args.GetReturnValue().Set(Number::New(isolate, num));
}

void InitAll(Local<Object> exports) {
//   Wrapper::Init(exports);
    NODE_SET_METHOD(exports, "getPrimeUnder", method);
}

NODE_MODULE(test, InitAll)