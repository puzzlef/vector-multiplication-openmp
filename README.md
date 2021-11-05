Comparing various *schedules* for *OpenMP-based* **element-by-element vector multiplication**.

Two floating-point vectors `x` and `y`, with number of **elements** from `1E+6`
to `1E+9` were multiplied using OpenMP. Each element count was attempted with
various **OpenMP schedule configs**, running each config 5 times to get a good
time measure. Multiplication here represents any memory-aligned independent
operation, or a `map()` operation. Results indicate a **num-threads** of `32`,
and a **schedule-kind** of `auto` to be suitable (for **float**).

All outputs are saved in [out](out/) and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets].

<br>

```bash
$ g++ -O3 -fopenmp main.cxx
$ ./a.out

# ...
#
# Elements 1e+07
# [00002.210 ms] [1.644725] multiplySeq
# [00009.731 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 64]
# [00009.613 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 128]
# [00009.634 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 256]
# [00009.310 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 512]
# [00009.307 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 1024]
# [00009.328 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 2048]
# [00009.356 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 4096]
# [00009.323 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 8192]
# [00009.320 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 16384]
# [00009.300 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 32768]
# [00009.237 ms] [1.644725] multiplyOpenmp [1 threads; schedule static 65536]
# ...
```

[![](https://i.imgur.com/2gtDdEv.png)][sheetp]
[![](https://i.imgur.com/9TtYTvh.png)][sheetp]
[![](https://i.imgur.com/kDoKEVr.png)][sheetp]
[![](https://i.imgur.com/7sUkqcZ.png)][sheetp]
[![](https://i.imgur.com/015fCBk.png)][sheetp]

[![](https://i.imgur.com/exRwNpv.png)][sheetp]
[![](https://i.imgur.com/WI9DTDj.png)][sheetp]
[![](https://i.imgur.com/DbwMaCk.png)][sheetp]
[![](https://i.imgur.com/1QOVrAq.png)][sheetp]
[![](https://i.imgur.com/3wV7z9c.png)][sheetp]

<br>
<br>


## References

- [What's the difference between "static" and "dynamic" schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)
- [OpenMP Dynamic vs Guided Scheduling](https://stackoverflow.com/a/43047074/1413259)

<br>
<br>

[![](https://i.imgur.com/MJi0vOn.jpg)](https://knowyourcodelyokofacts.tumblr.com/post/49493220478/jeremy-belpois-jeremy-is-known-to-have-been)

[charts]: https://photos.app.goo.gl/FTjLSTf2w3oh3Rju6
[sheets]: https://docs.google.com/spreadsheets/d/1B8kQmQkjyvqnjG3wSYxVFpRLCCWJ_gGI_pNjfaiCpp0/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQDbuQPxr19ZhCxpXDUP-HwpvvPwnw4v-0ZGTE_9qFCStkCauPnGG_rDGQSNyurM6CMj2F6ql_pXGLG/pubhtml
