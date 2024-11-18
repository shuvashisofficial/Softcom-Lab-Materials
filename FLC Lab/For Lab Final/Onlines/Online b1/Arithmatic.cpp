//Write a C program that will scan an input file (c source code) and find out how many arithmetic operations are done in the input program.

#include <stdio.h>
#include <ctype.h>

int isArithmeticOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int main() {
    FILE *file;
    char fileName[100];
    char c;
    int operationCount = 0;
    int checkAfterPercent = 0;  // Flag to check characters after '%'

    printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Arithmetic operations:\n");

    while ((c = getc(file)) != EOF) {
        if (isArithmeticOperator(c)) {
            char nextChar = getc(file);

            // Check for exceptions like %d, %f, %lf
            if (!(nextChar == 'd' || nextChar == 'f' || nextChar == 'l')) {
                operationCount++;
                printf("%c", c);
                printf("%c", nextChar);
            }

            // Set flag to skip characters after '%'
            checkAfterPercent = (nextChar == '%');

            // Unget the character if it's not part of the arithmetic operation
            if (!checkAfterPercent) {
                ungetc(nextChar, file);
            }
        } else {
            // Reset the flag if the current character is not '%'
            checkAfterPercent = 0;
        }

        // Skip characters after '%' until a non-alphabetic character is encountered
        while (checkAfterPercent && isalpha(c = getc(file))) {}
    }

    fclose(file);

    printf("\nNo. of operations: %d\n", operationCount);

    return 0;
}
