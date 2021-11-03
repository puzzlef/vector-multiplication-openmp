#pragma once
#include "_main.hxx"




struct MultiplyOptions {
  int repeat;
  int threads;
  int scheduleKind;
  int chunkSize;

  MultiplyOptions(int repeat=1, int threads=1, int scheduleKind=omp_sched_static, int chunkSize=64) :
  repeat(repeat), threads(threads), scheduleKind(scheduleKind), chunkSize(chunkSize) {}
};
