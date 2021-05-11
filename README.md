Performance of sequential execution based vs OpenMP based vector multiply.

This experiment was for comparing the performance between:
1. Find `x*y` using a single thread (**sequential**).
2. Find `x*y` accelerated using **OpenMP**.

Here `x`, `y` are both floating-point vectors. Both approaches were attempted
on a number of vector sizes, running each approach 5 times per size to get a
good time measure. While it might seem that **OpenMP** method would be a clear
winner, the results indicate it is not the case. This is possibly because of
high communication costs, and not enough computational workload as indicated
by [this answer].

```bash
$ g++ -O3 -fopenmp main.cxx
$ OMP_NUM_THREADS=4 ./a.out

# [00000.005 ms; 1e+04 elems.] [1.644834] multiply
# [00000.081 ms; 1e+04 elems.] [1.644834] multiplyOmp
#
# [00000.034 ms; 1e+05 elems.] [1.644924] multiply
# [00000.058 ms; 1e+05 elems.] [1.644924] multiplyOmp
#
# [00000.385 ms; 1e+06 elems.] [1.644933] multiply
# [00000.700 ms; 1e+06 elems.] [1.644933] multiplyOmp
#
# [00004.217 ms; 1e+07 elems.] [1.644934] multiply
# [00009.310 ms; 1e+07 elems.] [1.644934] multiplyOmp
#
# [00039.891 ms; 1e+08 elems.] [1.644934] multiply
# [00092.159 ms; 1e+08 elems.] [1.644934] multiplyOmp
#
# [00409.015 ms; 1e+09 elems.] [1.644934] multiply
# [00894.247 ms; 1e+09 elems.] [1.644934] multiplyOmp
```

```bash
$ g++ -O3 -fopenmp main.cxx
$ OMP_NUM_THREADS=48 ./a.out

# [00000.003 ms; 1e+04 elems.] [1.644834] multiply
# [00023.995 ms; 1e+04 elems.] [1.644834] multiplyOmp
#
# [00000.034 ms; 1e+05 elems.] [1.644924] multiply
# [00024.159 ms; 1e+05 elems.] [1.644924] multiplyOmp
#
# [00000.495 ms; 1e+06 elems.] [1.644933] multiply
# [00023.299 ms; 1e+06 elems.] [1.644933] multiplyOmp
#
# [00003.968 ms; 1e+07 elems.] [1.644934] multiply
# [00021.626 ms; 1e+07 elems.] [1.644934] multiplyOmp
#
# [00039.168 ms; 1e+08 elems.] [1.644934] multiply
# [00079.011 ms; 1e+08 elems.] [1.644934] multiplyOmp
#
# [00400.236 ms; 1e+09 elems.] [1.644934] multiply
# [00648.833 ms; 1e+09 elems.] [1.644934] multiplyOmp
```

<br>
<br>


## References

- [open MP - dot product][this answer]
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)

<br>
<br>

[![](https://i.imgur.com/NoHtf8A.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)

[this answer]: https://stackoverflow.com/a/5368572/1413259
