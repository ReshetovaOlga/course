add_library(data_structures
        bitset/bitset.c
        unordered_array_set/unordered_array_set.c
        ordered_array_set/ordered_array_set.c
        matrix/matrix.c matrix/matrix.h
        matrix_tasks/matrix_tasks.c
        matrix_tasks/matrix_tasks.h
        string/string.c
        string/string.h
        string/tasks/removeNonLetters.c
        string/tasks/removeNonLetters.h
        string/tasks/removeAdjacentEqualLetters.c
        string/tasks/removeAdjacentEqualLetters.h
        "string/tasks/firstTheNumbersAreInvertedThenTheLetters.c"
        "string/tasks/firstTheNumbersAreInvertedThenTheLetters.h"
        string/tasks/firstLettersThenNumbers.c
        string/tasks/firstLettersThenNumbers.h
        "string/tasks/ howManyDigitsAreThereSoManySpaces.c"
        "string/tasks/ howManyDigitsAreThereSoManySpaces.h"
        string/tasks/replaceAllOccurrencesOfTheWord1WithTheWord2.c
        string/tasks/replaceAllOccurrencesOfTheWord1WithTheWord2.h
        string/tasks/6AreTheWordsLexicographicallyOrdered.c
        string/tasks/6AreTheWordsLexicographicallyOrdered.h
        string/tasks/7theWordsOfTheStringAreInReverseOrder.c
        string/tasks/7theWordsOfTheStringAreInReverseOrder.h
        sortAndDifficultyAssessment/sortAndDifficultyAssessment.c
        sortAndDifficultyAssessment/sortAndDifficultyAssessment.h)

target_link_libraries(data_structures algorithms)
