Comparing performance of *sequential* vs *OpenMP-based* **element-by-element vector multiplication**.

In each of the experiments given below, we multiply two floating-point vectors
`x` and `y`, with number of **elements** from `10^6` to `10^9` using OpenMP.
Each element count is attempted with various approaches, running each approach 5
times to get a good time measure. Multiplication here represents any
memory-aligned independent operation, or a `map()` operation.

<br>


### Adjusting OpenMP schedule

In this experiment ([adjust-schedule]), we multiply two floating-point vectors
`x` and `y` using OpenMP. Each element count is attempted with various **OpenMP**
**schedule configs**. Results indicate a **schedule-kind** of `auto` to be
suitable.

[adjust-schedule]: https://github.com/puzzlef/vector-multiplication-openmp/tree/adjust-schedule

<br>


### Comparision with Sequential implementation

In this experiment ([compare-sequential], [main]), we compare the performance
between finding `x*y` using a single thread (**sequential**), and using
**OpenMP**. Here `x`, `y` are both floating-point vectors, and the comparison in
performed on a number of vector sizes. Note that neither approach makes use of
*SIMD instructions* which are available on all modern hardware. While it might
seem that *OpenMP* method would be a clear winner, the results indicate it is
*not the case*. This is possibly because of high communication costs, and not
enough computational workload as indicated by [this answer]. However, **from 10⁸**
**elements, OpenMP approach performs better** than sequential. All outputs are
saved in [gist]. Some [charts] are also included below, generated from [sheets].

[![](https://i.imgur.com/Izuc0gw.png)][sheetp]
[![](https://i.imgur.com/kGKSaG3.png)][sheetp]

[compare-sequential]: https://github.com/puzzlef/vector-multiplication-openmp/tree/compare-sequential
[main]: https://github.com/puzzlef/vector-multiplication-openmp

<br>
<br>


## References

- [open MP - dot product][this answer]
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)
- [Git pulling a branch from another repository?](https://stackoverflow.com/a/46289324/1413259)

<br>
<br>


[![](https://i.imgur.com/gHjBLSG.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)
![](https://ga-beacon.deno.dev/G-KD28SG54JQ:hbAybl6nQFOtmVxW4if3xw/github.com/puzzlef/vector-multiplication-openmp)

[this answer]: https://stackoverflow.com/a/5368572/1413259
[gist]: https://gist.github.com/wolfram77/f9dae5ec1b65ff87b65ab30deb3b1aa9
[charts]: https://photos.app.goo.gl/qfFxpy6v886ZQhja8
[sheets]: https://docs.google.com/spreadsheets/d/1IdlGlGqvn-Gprb5cpgzZU9QU3dfo3SgySajN5oDgkeQ/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQvlt3NQwk-G2wh-LjDn9KhL2gbk2C9RKfW0OQRzmDw7UhoEdCx6KBTN1xuv7Svg_eTQbmjj_92SOkw/pubhtml
