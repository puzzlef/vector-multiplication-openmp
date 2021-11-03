#pragma once
#include "_main.hxx"




struct MultiplyOptions {
  int repeat;
  int gridLimit;
  int blockSize;

  MultiplyOptions(int repeat=1, int gridLimit=GRID_LIMIT, int blockSize=BLOCK_LIMIT) :
  repeat(repeat), gridLimit(gridLimit), blockSize(blockSize) {}
};
