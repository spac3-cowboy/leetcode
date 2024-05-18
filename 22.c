#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, char* current, int open, int close, int max) {
    if (strlen(current) == max * 2) {
        result[*returnSize] = (char*)malloc((max * 2 + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    if (open < max) 
    {
        strcat(current, "(");
        backtrack(result, returnSize, current, open + 1, close, max);
        current[strlen(current) - 1] = '\0';
    }
    if (close < open) 
    {
        strcat(current, ")");
        backtrack(result, returnSize, current, open, close + 1, max);
        current[strlen(current) - 1] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) 
{
    *returnSize = 0;
    char** result = (char**)malloc(16384 * sizeof(char*));
    char* current = (char*)malloc((n * 2 + 1) * sizeof(char));
    current[0] = '\0';
    backtrack(result, returnSize, current, 0, 0, n);
    free(current);
    return result;
}