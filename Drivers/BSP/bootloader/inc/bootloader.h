#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include "main.h"

typedef void (*load)(void);

void bootloader_brance(void);

#endif

