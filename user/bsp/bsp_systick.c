#include "bsp_systick.h"

volatile uint32_t delay_times = 0;

//搭配滴答定时器实现的精确ms延时
void delay_ms(uint32_t ms)
{
    delay_times = ms;
    while( delay_times != 0 );
}

//滴答定时器中断服务函数
void SysTick_Handler(void)
{
    if( delay_times != 0 )
    {
        delay_times--;
    }
}
