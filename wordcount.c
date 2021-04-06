#include <stdio.h>

#include <stdlib.h>
#include "htab.h"
#include "io.h"

//calculated by the number of words in vocabulary of an average person (20000-35000)
//data taken from site https://wordcounter.io/blog/how-many-words-does-the-average-person-know/
//taken average value - 27500 and added to the closest prime number
#define HTAB_SIZE 27509
#define MAX_WORD_LEN 127

int main(int argc, char *argv[])
{
    //TODO general file opening
    (void) argc; (void) argv;
    
    bool limit_reached = false;

    //TODO file opening was unsuccessful
    FILE *fr = fopen("short_text", "r");
    char *word = malloc(MAX_WORD_LEN);
    
    int length;
    while ((length = read_word(word, MAX_WORD_LEN, fr)) != EOF)
    {
        if (length == 0 && !limit_reached)
        {
            limit_reached = true;
            fprintf(stderr, "Text obsahuje prilis dlhe slova ktore budu skratene\n");
        }
        printf("%s\n", word);
        //do stuff with hash table
    }
    return 0;
}
