#include "cpoly.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

// base
typedef struct {
    int x;
    int y;
    // declare a vtable
    POLY_TABLE(Context, POLY_INTERFACE(print), POLY_INTERFACE(init))
} Context;

POLY_PROTOTYPE(void, init, Context *);
POLY_PROTOTYPE(void, print, Context *, int);

// derived  1
typedef struct {
    float o;
} glContext;

void gl_init(Context *ctx)
{
    ctx->x = 1;
    printf("gl init\n");
}

void gl_print(Context *ctx, int param)
{
    printf("gl print: x: %d param: %d\n", ctx->x, param);
}

POLY_DERIVED(Context, glContext, gl_ctor, POLY_IMPL(print, gl_print) POLY_IMPL(init, gl_init))

// derived 2
typedef struct {
    int o;
} vkContext;

void vk_init(Context *ctx)
{
    ctx->x = 2;
    printf("vk init\n");
}

void vk_print(Context *ctx, int param)
{
    assert(poly_cast(ctx, glContext) == NULL);
    printf("vk print: x: %d param: %d\n", poly_cast(ctx, vkContext)->o, param);
}

void vk_illegal(void)
{
}

POLY_DERIVED(Context, vkContext, vk_ctor, POLY_IMPL(print, vk_print) POLY_IMPL(init, vk_init))

// calling interface
void init(Context *ctx)
{
    poly_func(ctx, init)(ctx);
}

void print(Context *ctx)
{
    poly_func(ctx, print)(ctx, 123);
}

int main(int argc, char *argv[])
{
    Context *ctx = malloc(sizeof(Context));
    {
        glContext gl = {.o = 0.123};
        *ctx         = gl_ctor(&gl);
        printf("%f\n", poly_cast(ctx, glContext)->o);
        assert(poly_cast(ctx, glContext));
        assert(poly_cast(ctx, vkContext) == NULL);
        init(ctx);
        print(ctx);
    }
    {
        glContext gl = {.o = 0.456};
        *ctx         = gl_ctor(&gl);
        printf("%f\n", poly_cast(ctx, glContext)->o);
        init(ctx);
        print(ctx);
    }
    {
        vkContext vk = {.o = 789};
        *ctx         = vk_ctor(&vk);
        printf("%d\n", poly_cast(ctx, vkContext)->o);
        assert(poly_cast(ctx, vkContext));
        assert(poly_cast(ctx, glContext) == NULL);
        init(ctx);
        print(ctx);
    }

    return 0;
}
