#include "bootloader.h"
#include "ota_uart.h"
#include "delay.h"
#include "myiic.h"
#include "24cxx.h"
#include "stmflash.h"
#include "main.h"
load load_a;

void load_app(uint32_t addr)
{
    if (*(uint32_t *)addr >= 0x20000000 && *(uint32_t *)addr <= 0x20040000) {
        __set_MSP(*(uint32_t *)addr);
        load_a = (load)*(__volatile uint32_t *)(addr + 4);
        load_a();
    }

}

void bootloader_brance(void)
{
    if (OTA_Info.ota_flag == OTA_SET_FLAG) {
        printf("OTA升级中...");
    }
    else {
        printf("跳转APP程序...");
        load_app(F103RC_A_SADDR);
    }
}

