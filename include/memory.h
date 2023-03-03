/**
 * @file memory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MEMORY_GUARD
#define MEMORY_GUARD

#include <stdint.h>

/*======================================*/
/*      physical memory on dram chips   */
/*======================================*/

// physical memory space is decided by the physical address
// in this simulator, there are 4 + 6 + 6 = 16 bit physical adderss
// then the physical space is (1 << 16) = 65536
// total 16 physical memory
#define PHYSICAL_MEMORY_SPACE   (65536)
#define MAX_NUM_PHYSICAL_PAGE (16)    // 1 + MAX_INDEX_PHYSICAL_PAGE

#define PAGE_TABLE_ENTRY_NUM    (512)
#define PAGE_SIZE    (4096)

// physical memory
// 16 physical memory pages
// used only for user process
uint8_t pm[PHYSICAL_MEMORY_SPACE];

/*======================================*/
/*      memory R/W                      */
/*======================================*/

// used by instructions: use virtual address
uint64_t virtual_read_data(uint64_t vaddr);
void virtual_write_data(uint64_t vaddr, uint64_t data);
void virtual_read_inst(uint64_t vaddr, char *buf);
void virtual_write_inst(uint64_t vaddr, const char *str);

// used by instructions: read or write uint64_t to DRAM
uint64_t cpu_read64bits_dram(uint64_t paddr);
void cpu_write64bits_dram(uint64_t paddr, uint64_t data);
void cpu_readinst_dram(uint64_t paddr, char *buf);
void cpu_writeinst_dram(uint64_t paddr, const char *str);

void bus_read_cacheline(uint64_t paddr, uint8_t *block);
void bus_write_cacheline(uint64_t paddr, uint8_t *block);

#endif