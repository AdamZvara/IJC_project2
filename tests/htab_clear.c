/*
 * @brief Delte all records from table, task B) IJC - DU2
 * @file htab_clear.c
 * @author Adam Zvara, xzvara01 - FIT
 * @date 4.4.2021
 */

#include <stdlib.h>
#include "htab_private.h"

void htab_clear(htab_t *t)
{
    for (size_t i = 0; i < t->arr_size; i++)
    {
        for (htab_item_t *tmp = t->arr[i]; tmp != NULL; tmp = tmp->next)
        {
            free(tmp);
        }

        t->arr[i] = NULL;
    }

    t->size = 0;
}
