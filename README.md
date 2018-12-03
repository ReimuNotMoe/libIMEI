# libIMEI

## Introduction
IMEI generation and verification library.
- Generates valid IMEI numbers.
- Verifies if an IMEI number is valid.


## Build
### Dependencies
This project has no dependencies.
### Compile
Nearly all my projects use CMake. It's very simple:

    mkdir build
    cd build
    cmake ..
    make -j `nproc`

If you want to install compiled stuff to system (default location is `/usr/local/`), just run `make install`.


## How to use
You can have a look at the examples, `imei_generate.c` and `imei_verify.c`.


## Caveats
This library uses `/dev/urandom` directly as random number source. It may not work on non-POSIX platforms.
