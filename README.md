# Simple unit testing example with Check and CMake

This project is a complete C unit test with the Check library, using CMake as
a build tool.

## Status

[![BSD licensed](https://img.shields.io/github/license/vndmtrx/check-cmake-example.svg)](https://github.com/vndmtrx/check-cmake-example/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/vndmtrx/check-cmake-example.svg?branch=master)](https://travis-ci.org/vndmtrx/check-cmake-example)
[![codecov](https://img.shields.io/codecov/c/github/vndmtrx/check-cmake-example.svg)](https://codecov.io/gh/vndmtrx/check-cmake-example)

## Installing

To run this project the following programs need to be installed on your system:
- Cmake
- Check
- Gcov
- Lcov
- Valgrind

Then, do as follows:

```
$ mkdir build && cd build
$ cmake ..
$ make
$ make test
```

Don't do `make install` unless you want to install the `sample` library.

`sample.c` and `sample.h` are built as a library. `src/main.c:main()` is a
client of `libsample.a`, just as `tests/test_sample.c:main()`.

After running `make test`, you will find the test files into `Testing` folder.

### Code Coverage Support

This example implements Code Coverage Reports using either using either `gcov` or `lcov`.
If you want to check them, you should run the following command after `make test`:

```
$ make gcov
$ make lcov
```

The coverage reports will be into `Coverage` folder. In the case of `lcov`, you
can see into the browser, opening the `index.html` file on the folder above.

### Valgrind Support

This example also implements a memory leak check with `valgrind`, thus allowing
a full test of the application. If you want to check them, you
should run the following command after `make`:

```
$ make test_sample_valgrind
```

It is important to note that, unlike code coverage generation, for each
`add_executable` in the build, you will need to create a specific target for the
valgrind with `add_custom_target`.

In the future, we plan to make a macro to simplify this task. At this moment, we
only provide the means to add valgrind into build script.

## Thanks

We have done our best to keep the code as simple as possible, both in the
building scripts and in the test scripts, in order to be very straightforward
and easy to understand.

Corrections and suggestions are welcome. Feel free to fork this project and
propose suggestions through issues and pull requests.
