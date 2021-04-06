#include <stdio.h>

#include <stdlib.h>
#include "htab.h"
#include "io.h"

//calculated by the number of words in vocabulary of an average person 
//(lower value close to 20000)
//data taken from site https://wordcounter.io/blog/how-many-words-does-the-average-person-know/
//added to a prime number 
#define HTAB_SIZE 20011
#define MAX_WORD_LEN 127

void write_pair(htab_pair_t *data)
{
    printf("%s %d\n", data->key, data->value);
}

int main(int argc, char *argv[])
{
    //TODO general file opening
    (void) argc; (void) argv;
    
    //TODO file opening was unsuccessful
    FILE *fr = fopen("/usr/share/dict/words", "r");
    
    bool limit_reached = false;
    int length;
    
    htab_t *table = htab_init(HTAB_SIZE);
    if (table == NULL)
    {
        fprintf(stderr, "Alokacia tabulky neprebehla uspesne\n");
        fclose(fr);
        return 1;
    }

    char *word = malloc(MAX_WORD_LEN);
    if (word == NULL)
    {
        htab_free(table);
        fprintf(stderr, "Alokacia slova neprebehla uspesne\n");
        fclose(fr);
        return 1;
    }

    htab_pair_t *pair;
    while ((length = read_word(word, MAX_WORD_LEN, fr)) != EOF)
    {
        if (length == 0 && !limit_reached)
        {
            limit_reached = true;
            fprintf(stderr, "Text obsahuje prilis dlhe slova ktore budu skratene\n");
        }
        
        pair = htab_lookup_add(table, word);
        if (pair == NULL) 
        {
            htab_free(table);
            free(word);
            fprintf(stderr, "Alokacia prvku tabulky neprebehla uspesne\n");
            fclose(fr);
            return -1;
        }

        pair->value++;
    }

    htab_for_each(table, (*write_pair));

    htab_free(table);
    fclose(fr);
    return 0;
}
