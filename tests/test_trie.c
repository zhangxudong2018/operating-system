/**
 * @file test_trie.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "algorithm.h"

void trie_print(trie_node_t *root);

static void test_insert()
{
    printf("Testing Trie ...\n");

    trie_node_t *root = trie_construct();
    uint64_t result;

    root = trie_insert(root, "abcd", 12);
    root = trie_insert(root, "ab", 108);
    root = trie_insert(root, "abef", 1022);

    assert(trie_get(root, "abcd", &result) == 1);
    assert(result == 12);
    assert(trie_get(root, "ab", &result) == 1);
    assert(result == 108);
    assert(trie_get(root, "abef", &result) == 1);
    assert(result == 1022);

    assert(trie_get(root, "a", &result) == 0);
    assert(trie_get(root, "abc", &result) == 0);
    assert(trie_get(root, "b", &result) == 0);
    assert(trie_get(root, "x", &result) == 0);

    trie_free(root);

    printf(GREENSTR("Pass\n"));
}

int main()
{
    test_insert();
}