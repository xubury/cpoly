#pragma once

#include <Context.h>

typedef struct {
    float o;
} glContext;

POLY_DECLARE_DERIVED(Context, glContext, gl_ctor)

