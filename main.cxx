#include <vector>
#include <cstdio>
#include "src/main.hxx"

using namespace std;




void runMultiply(int N) {
  int repeat = 5;
  vector<double> a1(N), a2(N);
  vector<double> x(N), y(N);
  for (int i=0; i<N; i++) {
    x[i] = 1.0/(i+1);
    y[i] = 1.0/(i+1);
  }

  // Find x*y using a single thread.
  double t1 = measureDuration([&]() { multiply(a1, x, y); }, repeat);
  printf("[%09.3f ms; %.0e elems.] [%f] multiply\n", t1, (double) N, sum(a1));

  // Find x*y accelerated using OpenMP.
  double t2 = measureDuration([&]() { multiplyOmp(a2, x, y); }, repeat);
  printf("[%09.3f ms; %.0e elems.] [%f] multiplyOmp\n", t2, (double) N, sum(a2));
}


int main(int argc, char **argv) {
  for (int n=10000; n<=1000000000; n*=10) {
    runMultiply(n);
    printf("\n");
  }
  return 0;
}
