#pragma once

#include <cpoly.h>

// base
typedef struct {
    int x;
    int y;
    // declare a vtable
    POLY_TABLE(Context, POLY_INTERFACE(print), POLY_INTERFACE(init), POLY_INTERFACE(get_type))
} Context;

#define TYPE_GL 1
#define TYPE_VK 2

POLY_PROTOTYPE(void, init, Context *);
POLY_PROTOTYPE(void, print, Context *, int);
POLY_PROTOTYPE(int, get_type);
