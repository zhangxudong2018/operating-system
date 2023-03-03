/**
 * @file dram.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <string.h>
#include <assert.h>
#include "cpu.h"
#include "address.h"
#include "memory.h"

#ifdef USE_SRAM_CACHE

uint8_t sram_cache_read(uint64_t paddr);
void sram_cache_write(uint64_t paddr, uint8_t data);

#endif

#ifdef USE_PAGETABLE_VA2PA 

void pagemap_update_time(uint64_t ppn);
void pagemap_dirty(uint64_t ppn);

#endif