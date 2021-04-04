#include <stdio.h>
#include "htab.h"

int main(int argc, char *argv[])
{
    (void) argc; (void) argv;

    htab_t *table = htab_init(0);
    return 0;
}
