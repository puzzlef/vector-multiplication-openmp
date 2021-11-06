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
$ ./a.out

# [00000.164 ms; 1e+06 elems.] [1.644725] multiplySeq
# [00000.291 ms; 1e+06 elems.] [1.644725] multiplyOpenmp
# [00002.108 ms; 1e+07 elems.] [1.644725] multiplySeq
# [00002.654 ms; 1e+07 elems.] [1.644725] multiplyOpenmp
# [00046.979 ms; 1e+08 elems.] [1.644725] multiplySeq
# [00040.584 ms; 1e+08 elems.] [1.644725] multiplyOpenmp
# [00398.860 ms; 1e+09 elems.] [1.644725] multiplySeq
# [00295.718 ms; 1e+09 elems.] [1.644725] multiplyOpenmp
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
