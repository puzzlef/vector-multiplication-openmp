#pragma once
#include <vector>

using std::vector;




template <class T>
auto sum(const T *x, int N) {
  T a = T();
  for (int i=0; i<N; i++)
    a += x[i];
  return a;
}

template <class T>
auto sum(const vector<T>& x) {
  return sum(x.data(), x.size());
}
