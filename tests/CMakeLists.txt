cmake_minimum_required(VERSION 2.8.2)
project(ijc_tests)

include(GoogleTest.cmake)

# Test targets
enable_testing()


add_executable(htab_test
    htab_test.cpp

# list your htab .c files here
    htab_hash_function.c
    htab_init.c
    htab_move.c
    htab_size.c
    htab_bucket_count.c
    htab_find.c
    htab_lookup_add.c
    htab_erase.c
    htab_for_each.c
    htab_clear.c
    htab_free.c
# ...
)
target_link_libraries(htab_test gtest_main)
GTEST_ADD_TESTS(htab_test "" htab_test.cpp)
