#include "bootloader.h"
#include "ota_uart.h"
#include "delay.h"
#include "myiic.h"
#include "24cxx.h"
#include "stmflash.h"
#include "main.h"
load load_a;
extern UART_HandleTypeDef g_ota_uart_handle;

void load_app(uint32_t addr)
{

    if (((*(__IO uint32_t *)addr) & 0X2FFE0000) == 0x20000000) {
        load_a = (load)(*(__IO uint32_t *)(addr + 4));
         __set_MSP(*(__IO uint32_t *)addr);//
        load_a();
    }
}

void bootloader_brance(void)
{
    if (OTA_Info.ota_flag == OTA_SET_FLAG) {
        printf("OTA升级中...");
        printf("\r\n");
    }
    else {
        printf("跳转APP程序...\r\n");
        printf("\r\n");
        load_app(F103RC_A_SADDR);
    }
}

