#include "drv_common.h"

/**
 * @brief 毫秒级延时
 * 
 * @param ms 延时的时间
 */
void drv_delay(uint32_t ms) {
    HAL_Delay(ms);
}

/**
 * @brief 微秒级延时
 * 
 * @param us 延时的时间，范围：[0-1000)
 */
void drv_us_delay(uint32_t us) {
    uint32_t start, now, delta, reload, us_tick;
    start   = SysTick->VAL;
    reload  = SysTick->LOAD;
    us_tick = SystemCoreClock / 1000000UL;
    do {
        now   = SysTick->VAL;
        delta = start >= now ? start - now : reload + start - now;
    } while (delta < us_tick * us);
}