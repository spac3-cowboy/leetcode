#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    // Define the Roman numerals and their corresponding values
    char* symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    // Allocate memory for the result string
    char* result = malloc(16 * sizeof(char));
    result[0] = '\0';  // Initialize the string to be empty

    // Loop over the Roman numerals from largest to smallest
    for (int i = 0; i < 13; i++) {
        // While the current Roman numeral can be subtracted from num
        while (num >= values[i]) {
            // Append the Roman numeral to the result string
            strcat(result, symbols[i]);
            // Subtract the value of the Roman numeral from num
            num -= values[i];
        }
    }

    return result;
}