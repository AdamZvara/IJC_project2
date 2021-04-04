/**
 * @brief Create private structure (hash table) for library
 * @file htab_private.h
 * @author Adam Zvara
 * @date 4.4.2021
 */

#include "htab.h"

/* HTAB structure where size = 3, arr_size = 2
  +----------+
  |   size   | number of records [key,data),next]
  +----------+
  | arr_size | size of the following array 
  +----------+
  |ptr|-->[(key,data),next]-->[(key,data),next]-->[(key,data),next]--|
  +---+
  |ptr|--|
  +---+
*/

/**
 * @struct htab
 * @brief Private declaration of hash table structure for library
 */
struct htab {
    size_t size;
    size_t arr_size;
    htab_pair_t *arr[];
};
