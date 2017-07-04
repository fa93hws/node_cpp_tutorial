#include <node.h>
#include <node_object_wrap.h>
#include "./demo_lib.h"

class Wrapper : public node::ObjectWrap {
    private:
        double a = 1;
        explicit Wrapper(double in = 0);
        ~Wrapper();
        static v8::Persistent<v8::Function> constructor;
        static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    public:
        static void Init(v8::Local<v8::Object> exports);
        static void getA(const v8::FunctionCallbackInfo<v8::Value>& args);
};