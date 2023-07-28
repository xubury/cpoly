# cpoly

Single header library to simulate basic polymorphism in C.

## Usage

Include `cpoly.h` in your project to use it.

`example` demonstrate how to create a base type `Context` with interfaces, and two derived type `glContext` and `vkContext` with their own interface implementation.

To compile and run `example`, install `CMake` and run `CMake -G YOUR_GENERATOR -B build` and `CMake --build build`.
