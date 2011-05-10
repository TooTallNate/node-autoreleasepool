#include <v8.h>
#include <node.h>
#import <Foundation/Foundation.h>

using namespace node;
using namespace v8;

class AutoreleasePool : ObjectWrap {
  private:
    NSAutoreleasePool* pool;

  public:


  static Persistent<FunctionTemplate> s_ct;

  static void Init(v8::Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);

    s_ct = Persistent<FunctionTemplate>::New(t);
    s_ct->InstanceTemplate()->SetInternalFieldCount(1);
    s_ct->SetClassName(String::NewSymbol("NSAutoreleasePool"));

    NODE_SET_PROTOTYPE_METHOD(s_ct, "drain", Drain);

    target->Set(String::NewSymbol("AutoreleasePool"),
                s_ct->GetFunction());
  }

  AutoreleasePool() {
    pool = [[NSAutoreleasePool alloc] init];
  }

  static v8::Handle<Value> New(const Arguments& args) {
    HandleScope scope;
    AutoreleasePool* p = new AutoreleasePool();
    p->Wrap(args.This());
    return args.This();
  }

  static v8::Handle<Value> Drain(const Arguments& args) {
    HandleScope scope;
    AutoreleasePool* ap = ObjectWrap::Unwrap<AutoreleasePool>(args.This());
    NSAutoreleasePool* pool = ap->pool;
    [pool drain];
    return scope.Close(Undefined());
  }

};

Persistent<FunctionTemplate> AutoreleasePool::s_ct;

extern "C" {
  static void init (v8::Handle<Object> target)
  {
    AutoreleasePool::Init(target);
  }

  NODE_MODULE(binding, init);
}
