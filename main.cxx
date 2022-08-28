#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <omp.h>
#include "src/main.hxx"

using namespace std;




// You can define datatype with -DTYPE=...
#ifndef TYPE
#define TYPE float
#endif
// You can define number of threads with -DMAX_THREADS=...
#ifndef MAX_THREADS
#define MAX_THREADS 12
#endif




void runMultiply(int N, int repeat) {
  using T = TYPE;
  vector<T> x(N), y(N), a(N);
  // Initialize x, y.
  for (int i=0; i<N; i++) {
    x[i] = 1.0/(i+1);
    y[i] = 1.0/(i+1);
  }
  // Find x*y using a single thread.
  do {
    float t = measureDuration([&]() { multiplyValues(x, y, a); }, repeat);
    printf("[%09.3f ms] [%f] multiplySeq\n", t, sumValues(a));
  } while (0);
  // Find x*y accelerated using OpenMP (static schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_static, chunkSize);
    float t = measureDuration([&]() { multiplyValuesOmp(x, y, a); }, repeat);
    printf("[%09.3f ms] [%f] multiplyOmp {sch_kind: static, chunk_size: %d}\n", t, sumValues(a), chunkSize);
  }
  // Find x*y accelerated using OpenMP (dynamic schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_dynamic, chunkSize);
    float t = measureDuration([&]() { multiplyValuesOmp(x, y, a); }, repeat);
    printf("[%09.3f ms] [%f] multiplyOmp {sch_kind: dynamic, chunk_size: %d}\n", t, sumValues(a), chunkSize);
  }
  // Find x*y accelerated using OpenMP (guided schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_guided, chunkSize);
    float t = measureDuration([&]() { multiplyValuesOmp(x, y, a); }, repeat);
    printf("[%09.3f ms] [%f] multiplyOmp {sch_kind: guided, chunk_size: %d}\n", t, sumValues(a), chunkSize);
  }
  // Find x*y accelerated using OpenMP (auto schedule).
  for (int chunkSize=1; chunkSize<=65536; chunkSize*=2) {
    omp_set_schedule(omp_sched_auto, chunkSize);
    float t = measureDuration([&]() { multiplyValuesOmp(x, y, a); }, repeat);
    printf("[%09.3f ms] [%f] multiplyOmp {sch_kind: auto, chunk_size: %d}\n", t, sumValues(a), chunkSize);
  }
}


int main(int argc, char **argv) {
  int repeat = argc>1? stoi(argv[1]) : 5;
  omp_set_num_threads(MAX_THREADS);
  printf("OMP_NUM_THREADS=%d\n", MAX_THREADS);
  for (int N=1000000; N<=1000000000; N*=10) {
    printf("# Elements %.0e\n", (double) N);
    runMultiply(N, repeat);
    printf("\n");
  }
  return 0;
}
