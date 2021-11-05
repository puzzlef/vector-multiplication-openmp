Comparing various launch configs for CUDA based vector multiply.

`TODO!`

Two floating-point vectors `x` and `y`, with number of **elements** from `1E+6` to `1E+9` were multiplied using CUDA. Each element count was attempted with various **CUDA launch configs**, running each config 5 times to get a good time measure. Multiplication here represents any memory-aligned independent operation, or a `map()` operation. Results indicate that a **grid_limit** of `16384/32768`, and a **block_size** of `128/256` to be suitable for both **float** and **double**. Using a **grid_limit** of `MAX` and a **block_size** of `256` could be a decent choice.

All outputs are saved in [out](out/) and a small part of the output is listed here. [Nsight Compute] profile results are saved in [prof](prof/). Some [charts] are also included below, generated from [sheets]. This experiment was done with guidance from [Prof. Dip Sankar Banerjee] and [Prof. Kishore Kothapalli].

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -O3 main.cu
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

[![](https://i.imgur.com/bGUUPot.gif)][sheetp]
[![](https://i.imgur.com/eLQ7XpP.gif)][sheetp]

[![](https://i.imgur.com/IagoPuk.gif)][sheetp]
[![](https://i.imgur.com/4L394Vk.gif)][sheetp]

[![](https://i.imgur.com/tCUuW0a.gif)][sheetp]
[![](https://i.imgur.com/tZaV8K6.gif)][sheetp]

[![](https://i.imgur.com/U6jbPeH.gif)][sheetp]
[![](https://i.imgur.com/mpjbvkK.gif)][sheetp]

[![](https://i.imgur.com/TVSzgPr.png)][sheetp]
[![](https://i.imgur.com/edMTlIA.png)][sheetp]
[![](https://i.imgur.com/g5oxQ1H.png)][sheetp]
[![](https://i.imgur.com/1Jyepy2.png)][sheetp]

<br>
<br>


## References

- [CUDA by Example :: Jason Sanders, Edward Kandrot](https://www.slideshare.net/SubhajitSahu/cuda-by-example-notes)

<br>
<br>

[![](https://i.imgur.com/lRwvZLe.png)](https://www.youtube.com/watch?v=vTdodyhhjww)
[![DOI](https://zenodo.org/badge/375073607.svg)](https://zenodo.org/badge/latestdoi/375073607)

[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[Nsight Compute]: https://developer.nvidia.com/nsight-compute
[charts]: https://photos.app.goo.gl/xorYb1MZSNqxUgNy7
[sheets]: https://docs.google.com/spreadsheets/d/1fWcVNQbANgiNepryktAsIWUHCNiAi-Yf1qQyiLsTJio/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQ5RS676pMmWtXRj0AaPSkBDdFHZWTEDgyMJGDq2mdSz7GfWektVErY130Y84eTAxuCMDGogdvLEzyZ/pubhtml
