#ifndef __HARDWARE_CONFIG__
#define __HARDWARE_CONFIG__

#include "ti_msp_dl_config.h"
#include "bsp_systick.h"


/********** 主函数部分 **********/

// @note 外部调用的inline需要在.h中写，因为inline是编译期建议，而.c.h相互绑定时链接时操作，所以直接在.h中实现。inline函数，如果引用之后未使用，那就会被优化掉，不需要单独处理

/**
 * @brief 主函数的init部分。
 * 
 */
static inline void hardware_init()
{
    delay_ms(100);
}

extern uint64_t count;

/**
 * @brief 主函数while循环部分
 * 
 */
static inline void app_while()
{
    DL_GPIO_clearPins(GPIO_OTHER_PORT, GPIO_OTHER_PIN_B22_PIN); // 输出低电平
    delay_ms(100);
    DL_GPIO_setPins(GPIO_OTHER_PORT, GPIO_OTHER_PIN_B22_PIN); // 输出高电平
    delay_ms(100);

    count++;
}

/********** 主函数结束 **********/



#endif // __HARDWARE_CONFIG__
