//
// Created by elen_ on 08.03.2022.
//

#include " howManyDigitsAreThereSoManySpaces.h"

// Преобразовать строку, заменяя каждую цифру соответствующим ей числом
//пробелов
void howManyDigitsAreThereSoManySpaces(char *beginString) {
    char *_stringBuffer = malloc(MAX_STRING_SIZE + 1);
    char *endStringBuffer = copy(beginString, getEndOfString(beginString), _stringBuffer);

    while (_stringBuffer < endStringBuffer) {
        if (isdigit(*_stringBuffer)) {
            int digit = *_stringBuffer - '0';
            while (digit > 0) {
                *beginString = ' ';
                beginString++;
                digit--;
            }
        } else {
            *beginString = *_stringBuffer;
            beginString++;
        }
        _stringBuffer++;
    }

    *beginString = '\0';

    free(_stringBuffer);
}
