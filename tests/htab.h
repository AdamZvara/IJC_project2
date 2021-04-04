/*
 * @brief Interface for libhtab libraries
 * @file htab.h
 * @author Taken from IJC project page 
 * @date 3.4.2021
 */


#ifndef __HTAB_H__
#define __HTAB_H__

#include <string.h>
#include <stdbool.h>  


struct htab;                    //partial declaration
typedef struct htab htab_t;

typedef const char * htab_key_t;
typedef int htab_value_t;

typedef struct htab_pair {
    htab_key_t   key;
    htab_value_t value;
} htab_pair_t;

//hash function
size_t htab_hash_function(htab_key_t str);

//functions for working with the table
htab_t *htab_init(size_t n);                  //table constructor
htab_t *htab_move(size_t n, htab_t *from);    //move data to new table
size_t htab_size(const htab_t * t);           //number of records in a table
size_t htab_bucket_count(const htab_t * t);   //length of array

htab_pair_t * htab_find(htab_t * t, htab_key_t key);  // hledání
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);

bool htab_erase(htab_t * t, htab_key_t key);    // ruší zadaný záznam

// Apply function f to each record in a table
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));

void htab_clear(htab_t * t);    //</delete all records
void htab_free(htab_t * t);     //</destructor

#endif // __HTAB_H__
