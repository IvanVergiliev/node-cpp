#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int LEN = 1000000;

int main() {
  vector<double> v;
  for (int i = 0; i < LEN; ++i) {
    v.push_back(rand() / double(RAND_MAX));
  }
  clock_t start = clock();
  sort(v.begin(), v.end());
  printf("sorting took %lf\n", (clock() - start) / double(CLOCKS_PER_SEC));
}
