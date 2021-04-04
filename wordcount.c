#include <stdio.h>
#include "htab.h"

int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    htab_t *table = htab_init(3);
    return 0;
}
