#include "ota_uart.h"

uint8_t ota_rxbuff[OTA_RX_SIZE];

void ota_uart_init(uint32_t bandrate)
{
    __HAL_RCC_UART4_CLK_DISABLE();
}



