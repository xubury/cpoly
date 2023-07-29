#include <vkContext.h>
#include <glContext.h>
#include <stdio.h>
#include <assert.h>

void vk_init(Context *ctx)
{
    ctx->x = 2;
    printf("vk init\n");
}

void vk_print(Context *ctx, int param)
{
    assert(poly_safe_cast(ctx, glContext) == NULL);
    printf("vk print: x: %d param: %d\n", poly_cast(ctx, vkContext)->o, param);
}

int vk_type(void)
{
    return TYPE_VK;
}

POLY_DEFINE_DERIVED(Context, vkContext, vk_ctor, POLY_IMPL(init, vk_init), POLY_IMPL(print, vk_print),
                    POLY_IMPL(get_type, vk_type))
