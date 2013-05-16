#include <algorithm>
#include <string>
#include <vector>

#include <node.h>
#include <v8.h>

using namespace std;
using namespace v8;

Handle<Value> Sort(const Arguments& args) {
  HandleScope scope;
  if (args.Length() < 1 || !args[0]->IsArray()) {
    ThrowException(Exception::TypeError(String::New("First argument should be an array")));
    return Undefined();
  }
  Handle<Array> arr = Handle<Array>::Cast(args[0]);
  vector<double> v;
  for (int i = 0; i < arr->Length(); ++i) {
    v.push_back(arr->Get(i)->NumberValue());
  }
  sort(v.begin(), v.end());
  Handle<Array> res = Array::New(v.size());
  for (int i = 0; i < v.size(); ++i) {
    res->Set(i, Number::New(v[i]));
  }
  return scope.Close(res);
}

void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("sort"), FunctionTemplate::New(Sort)->GetFunction());
}

NODE_MODULE(algorithm, Init)
