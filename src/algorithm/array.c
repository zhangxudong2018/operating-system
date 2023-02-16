/**
 * @file array.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "algorithm.h"

array_t *array_construct(int size) 
{
    array_t *arr = malloc(sizeof(array_t));
    arr->count = 0;
    arr->size = size;
    arr->table = malloc(sizeof(uint64_t) * arr->size);
    return arr;
}

void array_free(array_t *arr)
{
    free(arr->table);
    free(arr);
}

array_t *array_insert(array_t *arr, uint64_t value)
{
    if (arr == NULL)
    {
        return NULL;
    }
    if (arr->count == arr->size)
    {
        // malloc to two twice size
        uint64_t *old_table = arr->table;
        arr->size = 2 * arr->size;
        arr->table = malloc(arr->size * sizeof(uint64_t));

        // copy from the old to the new
        for (int i = 0; i < arr->count; i++)
        {
            arr->table[i] = old_table[i];
        }
        // free the old table memory
        free(old_table);
    }
    // insert the new value
    arr->table[arr->count] = value;
    arr->count += 1;
    return arr;
}

int array_delete(array_t *arr, int index)
{
    if (arr == NULL || index < 0 || arr->count <= index) 
    {
        return 0;
    }
    if (arr->count - 1 <= arr->size / 4)
    {
        // shrink the table to half when payload is quater
        // 当有效负载为1/4时，缩表到一半
        uint64_t *old_table = arr->table;
        arr->size = arr->size / 2;
        arr->table = malloc(arr->size * sizeof(uint64_t));

        int j = 0;
        for (int i = 0; i < arr->count; i++)
        {
            if (i != index)
            {
                arr->table[j] = old_table[i];
                j += 1;
            }
        }
        arr->count -= 1;
        free(old_table);
        return 1;
    }
    else 
    {
        // copy move from index forward
        for (int i = index + 1; i < arr->count; i++)
        {
            if (0 <= i - 1)
            {
                arr->table[i - 1] = arr->table[i];
            }
        }
        arr->count -= 1;
        return 1;
    }
    return 0;
}

int array_get(array_t *arr, int index, uint64_t *valptr)
{
    if (index > arr->count)
    {
        return 0;
    }
    else 
    {
        *valptr = arr->table[index];
        return 1;
    }
}

#ifndef DEBUG_ARRAY

void print_array(array_t *arr)
{
    printf("array size: %u count: %u\n", arr->size, arr->count);
    for (int i = 0; i < arr->count; i++)
    {
        printf("\t[%d] %16llx\n", i, arr->table[i]);
    }
}

#endif