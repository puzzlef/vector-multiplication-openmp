#include <vector>
#include <cstdio>
#include "src/main.hxx"

using namespace std;




#define TYPE float


void runMultiply(int N, int repeat) {
  vector<TYPE> a1(N), a2(N);
  vector<TYPE> x(N), y(N);
  for (int i=0; i<N; i++) {
    x[i] = 1.0/(i+1);
    y[i] = 1.0/(i+1);
  }

  // Find x*y using a single thread.
  float t1 = multiplySeq(a1, x, y, {repeat});
  printf("[%09.3f ms; %.0e elems.] [%f] multiplySeq\n", t1, (double) N, sum(a1));

  // Find x*y accelerated using OpenMP.
  float t2 = multiplyOpenmp(a2, x, y, {repeat});
  printf("[%09.3f ms; %.0e elems.] [%f] multiplyOpenmp\n", t2, (double) N, sum(a2));
}


int main(int argc, char **argv) {
  int repeat = argc>1? stoi(argv[1]) : 5;
  for (int n=1000000; n<=1000000000; n*=10) {
    runMultiply(n, repeat);
    printf("\n");
  }
  return 0;
}
