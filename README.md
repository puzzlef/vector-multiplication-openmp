Performance of *sequential* vs *OpenMP-based* **element-by-element vector multiplication**.

This experiment was for comparing the performance between:
1. Find `x*y` using a single thread (**sequential**).
2. Find `x*y` accelerated using **OpenMP**.

Here `x`, `y` are both floating-point vectors. Both approaches were attempted on
a number of vector sizes, running each approach 5 times per size to get a good
time measure. Note that neither approach makes use of *SIMD instructions* which
are available on all modern hardware. While it might seem that *OpenMP* method
would be a clear winner, the results indicate it is *not the case*. This is
possibly because of high communication costs, and not enough computational
workload as indicated by [this answer]. However, **from 10⁸ elements, OpenMP**
**approach performs better** than sequential.

All outputs are saved in [gist] and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets].

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

[![](https://i.imgur.com/Izuc0gw.png)][sheetp]
[![](https://i.imgur.com/kGKSaG3.png)][sheetp]

<br>
<br>


## References

- [open MP - dot product][this answer]
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)

<br>
<br>

[![](https://i.imgur.com/gHjBLSG.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)

[this answer]: https://stackoverflow.com/a/5368572/1413259
[gist]: https://gist.github.com/wolfram77/f9dae5ec1b65ff87b65ab30deb3b1aa9
[charts]: https://photos.app.goo.gl/qfFxpy6v886ZQhja8
[sheets]: https://docs.google.com/spreadsheets/d/1IdlGlGqvn-Gprb5cpgzZU9QU3dfo3SgySajN5oDgkeQ/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQvlt3NQwk-G2wh-LjDn9KhL2gbk2C9RKfW0OQRzmDw7UhoEdCx6KBTN1xuv7Svg_eTQbmjj_92SOkw/pubhtml
