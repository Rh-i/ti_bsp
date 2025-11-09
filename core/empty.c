#include "ti_msp_dl_config.h"

#include "app_main.h"

int main(void)
{
    SYSCFG_DL_init();
    hardware_init();

    while (1)
    {
        app_while();
    }
}
