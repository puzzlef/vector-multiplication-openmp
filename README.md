Comparing various *schedules* for *OpenMP-based* **element-by-element vector multiplication**.

In this experiment, we multiplied two floating-point vectors `x` and `y`, with
number of **elements** from `10^6` to `10^9` using OpenMP. Each element count
was attempted with various **OpenMP schedule configs**, running each config 5
times to get a good time measure. Multiplication here represents any
memory-aligned independent operation, or a `map()` operation. Results indicate a
**schedule-kind** of `auto` to be suitable.

All outputs are saved in a [gist] and a small part of the output is listed here.
Some [charts] are also included below, generated from [sheets]. This experiment
was done with guidance from [Prof. Kishore Kothapalli] and
[Prof. Dip Sankar Banerjee].

<br>

```bash
$ g++ -std=c++17 -O3 -fopenmp main.cxx
$ ./a.out

# OMP_NUM_THREADS=12
# # Elements 1e+06
# [00000.307 ms] [1.644725] multiplySeq
# [00004.249 ms] [1.644725] multiplyOmp {sch_kind: static, chunk_size: 1}
# [00001.539 ms] [1.644725] multiplyOmp {sch_kind: static, chunk_size: 2}
# [00001.440 ms] [1.644725] multiplyOmp {sch_kind: static, chunk_size: 4}
# ...
#
# ...
# [00297.097 ms] [1.644725] multiplyOmp {sch_kind: auto, chunk_size: 16384}
# [00285.764 ms] [1.644725] multiplyOmp {sch_kind: auto, chunk_size: 32768}
# [00247.109 ms] [1.644725] multiplyOmp {sch_kind: auto, chunk_size: 65536}
```

[![](https://i.imgur.com/J4xMocj.png)][sheetp]
[![](https://i.imgur.com/wNTAU2k.png)][sheetp]
[![](https://i.imgur.com/fmtvqfy.png)][sheetp]
[![](https://i.imgur.com/Pa3OGzf.png)][sheetp]

<br>
<br>


## References

- [What's the difference between "static" and "dynamic" schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)
- [OpenMP Dynamic vs Guided Scheduling](https://stackoverflow.com/a/43047074/1413259)

<br>
<br>


[![](https://i.imgur.com/ykk7NyZ.jpg)](https://knowyourcodelyokofacts.tumblr.com/post/49493220478/jeremy-belpois-jeremy-is-known-to-have-been)<br>
[![DOI](https://zenodo.org/badge/424267392.svg)](https://zenodo.org/badge/latestdoi/424267392)


[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://faculty.iiit.ac.in/~kkishore/
[gist]: https://gist.github.com/wolfram77/f2946fdd44685b6ef95264bb199d35dd
[charts]: https://imgur.com/a/PQYvAvH
[sheets]: https://docs.google.com/spreadsheets/d/1B8kQmQkjyvqnjG3wSYxVFpRLCCWJ_gGI_pNjfaiCpp0/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQDbuQPxr19ZhCxpXDUP-HwpvvPwnw4v-0ZGTE_9qFCStkCauPnGG_rDGQSNyurM6CMj2F6ql_pXGLG/pubhtml
