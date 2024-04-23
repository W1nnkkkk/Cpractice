#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

wchar_t* addUnderscoresToWords(const wchar_t* input) {
    const wchar_t* delim = L" ";
    wchar_t* result = (wchar_t*)malloc(wcslen(input)*3*sizeof(wchar_t));
    result[0] = L'\0';

    if (result == NULL) {
        return NULL;
    }

    wchar_t *inputCopy = wcsdup(input);
    wchar_t *saftyPtr;
    wchar_t *token = wcstok(inputCopy, delim, &saftyPtr);

    while (token != NULL) {
        wcscat(result, L"_");
        wcscat(result, token);
        wcscat(result, L"_");

        token = wcstok(NULL, delim, &saftyPtr);
    }
    
    return result;
}

int main() {
    const wchar_t* input = L"Пример строки для теста";
    wchar_t* result = addUnderscoresToWords(input);

    if (result != NULL) {
        wprintf(L"Результат: %ls\n", result);
        free(result);
    } else {
        wprintf(L"Ошибка при выделении памяти.\n");
    }
    
    return 0;
}
