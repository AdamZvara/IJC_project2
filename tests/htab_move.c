/*
 * @brief Move contructor, task B) IJC - DU2
 * @file htab_move.c
 * @author Adam Zvara, xzvara01 - FIT
 * @date 4.4.2021
 */

#include "htab_private.h"

#define MIN(x,y) ((x < y) ? x : y)

htab_t *htab_move(size_t n, htab_t *from)
{
    htab_t *table = htab_init(n);
    if (table == NULL) return NULL;

    table->size = from->size;
    for (size_t i = 0; i < MIN(table->arr_size, from->arr_size); i++)
    {
        table->arr[i] = from->arr[i];
        from->arr[i] = NULL;
    }

    return table;
}
