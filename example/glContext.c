#include <glContext.h>
#include <stdio.h>

void gl_init(Context *ctx)
{
    ctx->x = 1;
    printf("gl init\n");
}

void gl_print(Context *ctx, int param)
{
    printf("gl print: x: %d param: %d\n", ctx->x, param);
}

int gl_type(void)
{
    return TYPE_GL;
}

POLY_DEFINE_DERIVED(Context, glContext, gl_ctor, POLY_IMPL(print, gl_print), POLY_IMPL(init, gl_init),
                    POLY_IMPL(get_type, gl_type))
