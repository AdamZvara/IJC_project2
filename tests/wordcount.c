#include <stdio.h>
#include "htab.h"

int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    htab_t *table = htab_init(3);
    htab_pair_t *pair = htab_lookup_add(table, "ab");
    printf("%s %d :\n", pair->key, pair->value);

    htab_pair_t *pair2 = htab_lookup_add(table, "ab");
    printf("%s %d :\n", pair->key, pair->value);
    return 0;
}
