#include <stdlib.h>
#include <string.h>

char* map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char* digits, int index, char* combination, char** result, int* returnSize) {
    if (index == strlen(digits)) {
        result[*returnSize] = (char*)malloc((index + 1) * sizeof(char));
        strcpy(result[*returnSize], combination);
        (*returnSize)++;
        return;
    }
    char* letters = map[digits[index] - '2'];
    for (int i = 0; i < strlen(letters); i++) {
        combination[index] = letters[i];
        backtrack(digits, index + 1, combination, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (strlen(digits) == 0) {
        return NULL;
    }
    char** result = (char**)malloc(2187 * sizeof(char*));  // 3^5 = 243, 4^4 = 256, 256 > 243, so 256 is enough
    char* combination = (char*)malloc((strlen(digits) + 1) * sizeof(char));
    combination[strlen(digits)] = '\0';
    backtrack(digits, 0, combination, result, returnSize);
    free(combination);
    return result;
}