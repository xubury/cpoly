#include <Context.h>
#include <glContext.h>
#include <vkContext.h>
#include <stdio.h>
#include <assert.h>

// calling interface
void init(Context *ctx)
{
    POLY_FUNC(ctx, init)(ctx);
}

void print(Context *ctx)
{
    POLY_FUNC(ctx, print)(ctx, 123);
}

int main(void)
{
    /* Output: */
    /*  0.123000 */
    /*  gl init */
    /*  gl print: x: 1 param: 123 */
    /*  0.456000 */
    /*  gl init */
    /*  gl print: x: 1 param: 123 */
    /*  789 */
    /*  vk init */
    /*  vk print: x: 789 param: 123 */
    {
        glContext gl  = {.o = 0.123};
        Context   ctx = gl_ctor(&gl);
        printf("%f\n", poly_cast(&ctx, glContext)->o);
        assert(POLY_FUNC(&ctx, get_type)() == TYPE_GL);
        assert(poly_safe_cast(&ctx, glContext));
        assert(poly_safe_cast(&ctx, vkContext) == NULL);
        init(&ctx);
        print(&ctx);
    }
    {
        glContext gl  = {.o = 0.456};
        Context   ctx = gl_ctor(&gl);
        assert(POLY_FUNC(&ctx, get_type)() == TYPE_GL);
        printf("%f\n", poly_cast(&ctx, glContext)->o);
        init(&ctx);
        print(&ctx);
    }
    {
        vkContext vk  = {.o = 789};
        Context   ctx = vk_ctor(&vk);
        assert(POLY_FUNC(&ctx, get_type)() == TYPE_VK);
        printf("%d\n", poly_cast(&ctx, vkContext)->o);
        assert(poly_safe_cast(&ctx, vkContext));
        assert(poly_safe_cast(&ctx, glContext) == NULL);
        init(&ctx);
        print(&ctx);
    }

    return 0;
}
