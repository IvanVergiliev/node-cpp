#include <cmath>
#include <cstdlib>

const int LEN = 10000000;

double a[LEN];
int main() {
  for (int i = 0; i < LEN; ++i) {
    a[i] = rand() / double(RAND_MAX);
  }
  for (int i = 0; i < LEN; ++i) {
    a[i] = sqrt(a[i]);
  }
}

#include <node.h>
#include <v8.h>

using namespace std;
using namespace v8;

Handle<Value> Sqrt(const Arguments& args) {
  HandleScope scope;
  if (args.Length() < 1 || !args[0]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("First argument should be a number")));
    return Undefined();
  }
  double value = args[0]->NumberValue();
  Handle<Number> res = Number::New(sqrt(value));
  return scope.Close(res);
}

void Init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("sqrt"), FunctionTemplate::New(Sqrt)->GetFunction());
}

NODE_MODULE(math, Init);
