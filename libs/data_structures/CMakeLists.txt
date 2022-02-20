add_library(data_structures
        bitset/bitset.c
        unordered_array_set/unordered_array_set.c
        ordered_array_set/ordered_array_set.c
        matrix/matrix.c matrix/matrix.h
        matrix_tasks/matrix_tasks.c
        matrix_tasks/matrix_tasks.h)

target_link_libraries(data_structures algorithms)
