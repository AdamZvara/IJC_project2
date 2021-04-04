#include <stdio.h>
#include "htab.h"

int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    htab_t *table = htab_init(3);
    htab_pair_t *pair = htab_lookup_add(table, "ab");
    pair = htab_lookup_add(table, "abc");

    htab_erase(table, "ab");
    return 0;
}
