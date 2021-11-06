Performance of sequential execution based vs OpenMP based vector multiply.

`TODO!`

This experiment was for comparing the performance between:
1. Find `x*y` using a single thread (**sequential**).
2. Find `x*y` accelerated using **OpenMP**.

Here `x`, `y` are both floating-point vectors. Both approaches were attempted
on a number of vector sizes, running each approach 5 times per size to get a
good time measure. While it might seem that **OpenMP** method would be a clear
winner, the results indicate it is **not the case**. This is possibly because
of high communication costs, and not enough computational workload as indicated
by [this answer]. Note that neither approach makes use of *SIMD instructions*
which are available on all modern hardware.

All outputs are saved in [out](out/) and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets]. This
experiment was done with guidance from [Prof. Dip Sankar Banerjee] and
[Prof. Kishore Kothapalli].

<br>

```bash
$ g++ -O3 -fopenmp main.cxx
$ OMP_NUM_THREADS=4 ./a.out

# [00000.002 ms; 1e+04 elems.] [1.644834] multiply
# [00000.056 ms; 1e+04 elems.] [1.644834] multiplyOmp
#
# [00000.030 ms; 1e+05 elems.] [1.644924] multiply
# [00000.063 ms; 1e+05 elems.] [1.644924] multiplyOmp
#
# [00000.320 ms; 1e+06 elems.] [1.644933] multiply
# [00000.548 ms; 1e+06 elems.] [1.644933] multiplyOmp
#
# [00004.015 ms; 1e+07 elems.] [1.644934] multiply
# [00008.688 ms; 1e+07 elems.] [1.644934] multiplyOmp
#
# [00039.967 ms; 1e+08 elems.] [1.644934] multiply
# [00088.077 ms; 1e+08 elems.] [1.644934] multiplyOmp
#
# [00455.378 ms; 1e+09 elems.] [1.644934] multiply
# [01528.429 ms; 1e+09 elems.] [1.644934] multiplyOmp
```

```bash
$ g++ -O3 -fopenmp main.cxx
$ OMP_NUM_THREADS=48 ./a.out

# [00000.006 ms; 1e+04 elems.] [1.644834] multiply
# [00019.631 ms; 1e+04 elems.] [1.644834] multiplyOmp
#
# [00000.025 ms; 1e+05 elems.] [1.644924] multiply
# [00000.029 ms; 1e+05 elems.] [1.644924] multiplyOmp
#
# [00000.333 ms; 1e+06 elems.] [1.644933] multiply
# [00000.189 ms; 1e+06 elems.] [1.644933] multiplyOmp
#
# [00004.090 ms; 1e+07 elems.] [1.644934] multiply
# [00006.126 ms; 1e+07 elems.] [1.644934] multiplyOmp
#
# [00039.141 ms; 1e+08 elems.] [1.644934] multiply
# [00064.325 ms; 1e+08 elems.] [1.644934] multiplyOmp
#
# [00418.629 ms; 1e+09 elems.] [1.644934] multiply
# [00625.270 ms; 1e+09 elems.] [1.644934] multiplyOmp
```

[![](https://i.imgur.com/s4QBnrS.gif)][sheets]

<br>
<br>


## References

- [open MP - dot product][this answer]
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)

<br>
<br>

[![](https://i.imgur.com/NoHtf8A.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)

[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[this answer]: https://stackoverflow.com/a/5368572/1413259
[charts]: https://photos.app.goo.gl/qfFxpy6v886ZQhja8
[sheets]: https://docs.google.com/spreadsheets/d/1IdlGlGqvn-Gprb5cpgzZU9QU3dfo3SgySajN5oDgkeQ/edit?usp=sharing
