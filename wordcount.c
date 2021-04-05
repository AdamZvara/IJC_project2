#include <stdio.h>
#include "htab.h"

int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    htab_t *table = htab_init(3);
    htab_lookup_add(table, "adam");
    htab_lookup_add(table, "tomas");
    htab_lookup_add(table, "miro");

    htab_t *table2 = htab_move(2, table);


    return 0;
}
