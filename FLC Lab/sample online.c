#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countIOFunctions(FILE *input, FILE *output) {
    char line[1024];
    int inputCount = 0, outputCount = 0;

    while (fgets(line, sizeof(line), input) != NULL) {
        // Check for input functions
        if (strstr(line, "scanf") != NULL) {
            inputCount++;
        }

        // Check for output functions
        if (strstr(line, "printf") != NULL) {
            outputCount++;
        }
    }

    // Print results to console
    //printf("No. of input functions: %d\n", inputCount);
    //printf("No. of output functions: %d\n", outputCount);

    // Print results to file
    fprintf(output, "No. of input functions: %d\n", inputCount);
    fprintf(output, "No. of output functions: %d\n", outputCount);
}

int main() {
    FILE *inputFile, *outputFile;

    inputFile = fopen("input1.c", "r");
    outputFile = fopen("output1.txt", "w");

    if (!inputFile) {
        printf("Error: Unable to open the input file!\n");
        return 1;
    }

    if (!outputFile) {
        printf("Error: Unable to create the output file!\n");
        fclose(inputFile);
        return 1;
    }

    countIOFunctions(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    // Display the modified content
    outputFile = fopen("output1.txt", "r");
    int currentChar;
    while ((currentChar = fgetc(outputFile)) != EOF)
        printf("%c", currentChar);

    fclose(outputFile);

    return 0;
}
