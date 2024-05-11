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
        wcscat(result, L" ");

        token = wcstok(NULL, delim, &saftyPtr);
    }
    
    return result;
}

int main() {
    int maxLength = 1000;
    wchar_t* input = (wchar_t*)malloc(maxLength * sizeof(wchar_t));
    fgetws(input, maxLength, stdin);
    input[wcslen(input) - 1] = ' ';
    wchar_t* result = addUnderscoresToWords(input);

    if (result != NULL) {
        FILE* outputFile = fopen("output.txt", "w");
        fputws(result, outputFile);
        fclose(outputFile);
        free(result);
    } else {
        wprintf(L"Ошибка при выделении памяти.\n");
    }
    free(input);
    
    return 0;
}
