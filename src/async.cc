#include <algorithm>
#include <string>
#include <vector>

#include <node.h>
#include <v8.h>

using namespace std;
using namespace v8;

struct AsyncSortData {
  vector<double> v;
  Persistent<Function> callback;

  ~AsyncSortData() {
    callback.Dispose();
  }
};

void sort(uv_work_t* req) {
  auto data = reinterpret_cast<AsyncSortData*>(req->data);
  sort(data->v.begin(), data->v.end());
};

void afterSort(uv_work_t* req) {
  HandleScope scope;
  auto data = reinterpret_cast<AsyncSortData*>(req->data);
  Handle<Array> res = Array::New(data->v.size());
  for (int i = 0; i < data->v.size(); ++i) {
    res->Set(i, Number::New(data->v[i]));
  }
  data->callback->Call(res, 1, (Handle<Value>[]){res});
  delete data;
  delete req;
}

Handle<Value> AsyncSort(const Arguments& args) {
  HandleScope scope;
  if (args.Length() < 2 || !args[0]->IsArray() || !args[1]->IsFunction()) {
    ThrowException(Exception::TypeError(String::New("Incorrect parameters; usage: sort(arr, function (sorted) {})")));
    return Undefined();
  }
  Handle<Array> arr = Handle<Array>::Cast(args[0]);
  uv_work_t* req = new uv_work_t;
  AsyncSortData* data = new AsyncSortData;
  req->data = data;
  for (int i = 0; i < arr->Length(); ++i) {
    data->v.push_back(arr->Get(i)->NumberValue());
  }
  data->callback = Persistent<Function>::New(Local<Function>::Cast(args[1]));
  uv_queue_work(uv_default_loop(), req, sort, afterSort);
  return True();
}

void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("sort"), FunctionTemplate::New(AsyncSort)->GetFunction());
}

NODE_MODULE(async, Init);

