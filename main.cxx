#include <vector>
#include <string>
#include <cstdio>
#include "src/main.hxx"

using namespace std;



#define TYPE float


void runMultiply(int N, int repeat) {
  vector<TYPE> a0(N), a1(N), a2(N), a3(N), a4(N);
  vector<TYPE> x(N), y(N);
  for (int i=0; i<N; i++) {
    x[i] = 1.0/(i+1);
    y[i] = 1.0/(i+1);
  }

  // Find x*y using a single thread.
  float t0 = multiplySeq(a0, x, y, {repeat});
  printf("[%09.3f ms] [%f] multiplySeq\n", t0, sum(a0));

  // Find x*y accelerated using OpenMP.
  int maxThreads = omp_get_max_threads();
  for (int i=0, threads=1; threads<=maxThreads; threads+=i&1? threads:threads/2, i++) {
    // Use static schedule.
    for (int chunkSize=64; chunkSize<=65536; chunkSize++) {
      float t1 = multiplyOpenmp(a1, x, y, {repeat, threads, omp_sched_static, chunkSize});
      printf("[%09.3f ms] [%f] multiplyOpenmp [%d threads; schedule static %d]\n", t1, sum(a1), threads, chunkSize);
    }

    // Use dynamic schedule.
    for (int chunkSize=64; chunkSize<=65536; chunkSize++) {
      float t2 = multiplyOpenmp(a2, x, y, {repeat, threads, omp_sched_dynamic, chunkSize});
      printf("[%09.3f ms] [%f] multiplyOpenmp [%d threads; schedule dynamic %d]\n", t2, sum(a2), threads, chunkSize);
    }

    // Use guided schedule.
    for (int chunkSize=64; chunkSize<=65536; chunkSize++) {
      float t3 = multiplyOpenmp(a3, x, y, {repeat, threads, omp_sched_guided, chunkSize});
      printf("[%09.3f ms] [%f] multiplyOpenmp [%d threads; schedule guided %d]\n", t3, sum(a3), threads, chunkSize);
    }

    // Use auto schedule.
    for (int chunkSize=64; chunkSize<=65536; chunkSize++) {
      float t4 = multiplyOpenmp(a4, x, y, {repeat, threads, omp_sched_auto, chunkSize});
      printf("[%09.3f ms] [%f] multiplyOpenmp [%d threads; schedule auto %d]\n", t4, sum(a4), threads, chunkSize);
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
