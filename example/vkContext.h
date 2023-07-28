#pragma once

#include <Context.h>

typedef struct {
    int o;
} vkContext;

POLY_DECLARE_DERIVED(Context, vkContext, vk_ctor)
