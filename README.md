# Google Test and Google Mock build2 package

## Description

Build2 package containing Google Test and Google Mock static libraries.

Products of this package are following static libraries:

- gtest static library without main function
- gtest_main static library with main function
- gmock static library (contains also gtest) without main function
- gmock_main static library (contains also gtest) with main function

## Cloning repository

```bash
git clone --recursive https://github.com/rsitko92/googletest-build2.git
```

## Prerequisites

- [build2](https://build2.org)
- [GCC](https://gcc.gnu.org) or [Clang](https://clang.llvm.org)

## Running package tests

Being in root directory of project run:

- using g++:

  ```bash
  bdep init -C @gcc cc config.cxx=g++
  b test
  ```

- using clang++:

  ```bash
  bdep init -C @clang cc config.cxx=clang++
  b test
  ```

## Using libgtest package in project with build2 build toolchain

1. Add libgtest package dependency to `manifest` file:

    ```bash
    depends: * libgtest >= 0.1.0
    ```

1. Add libgtest package repository to `repositories.manifest` file:

    ```bash
    :
    role: prerequisite
    location: https://github.com/rsitko92/googletest-build2.git#master
    ```

1. Import one of the below libraries in `buildfile` of target application:

   - gtest without main function:

     ```bash
     import libs += libgtest%liba{googletest/googletest/gtest}
     ```

   - gtest with main function:

     ```bash
     import libs += libgtest%liba{googletest/googletest/gtest_main}
     ```

   - gmock (contains also gtest) without main function:

     ```bash
     import libs += libgtest%liba{googletest/googlemock/gmock}
     ```

   - gmock (contains also gtest) with main function:

     ```bash
     import libs += libgtest%liba{googletest/googlemock/gmock_main}
     ```

1. Link one of the choosen libgtest static library in `libs` variable with target:

    Example linking to `hello` executable target:

    ```bash
    exe{hello}: {hxx ixx txx cxx}{**} $libs
    ```

1. Add appropriate include statement(s) in source/header files:

   - Google Test:

     ```cpp
     #include <gtest/gtest.h>
     ```

   - Google Mock:

     ```cpp
     #include <gmock/gmock.h>
     ```
