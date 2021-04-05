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

    if (from->arr_size > table->arr_size)
    {
        for (size_t i = MIN(table->arr_size, from->arr_size); i < from->arr_size; i++)
        {
            size_t new_index = htab_hash_function(from->arr[i]->pair.key);
            new_index %= table->arr_size;

            htab_item_t *tmp = table->arr[new_index];
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }

            tmp->next = from->arr[i];
        }
    }

    return table;
}
