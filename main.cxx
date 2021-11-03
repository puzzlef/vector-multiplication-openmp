#include <vector>
#include <string>
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
  printf("[%09.3f ms] [%f] multiplySeq\n", t1, sum(a1));

  // Find x*y accelerated using CUDA.
  for (int grid=1024; grid<=GRID_LIMIT; grid*=2) {
    for (int block=32; block<=BLOCK_LIMIT; block*=2) {
      float t2 = multiplyCuda(a2, x, y, {repeat, grid, block});
      printf("[%09.3f ms] [%f] multiplyCuda<<<%d, %d>>>\n", t2, sum(a2), grid, block);
    }
  }
}


int main(int argc, char **argv) {
  int repeat = argc>1? stoi(argv[1]) : 5;
  for (int n=1000000; n<=1000000000; n*=10) {
    printf("# Elements %.0e\n", (double) n);
    runMultiply(n, repeat);
    printf("\n");
  }
  return 0;
}
