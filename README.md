# tmc-blosc2
This is where the planned [TooManyCooks](https://github.com/tzcnt/TooManyCooks/) port of the [c-blosc2 compression library](https://github.com/Blosc/c-blosc2) will live. There's nothing here yet...

### TODO
- Port to C++.
- Provide templates to allow fixing certain runtime parameters at compile-time (e.g. ndim)
- use ex_asio + io_uring for file I/O, and ex_cpu to replace the inbuilt pthreads.
- break down operations into smaller vertical slices to exploit dynamic parallelism.
