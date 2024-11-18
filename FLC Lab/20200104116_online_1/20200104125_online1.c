#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *file;
    char line[256];
    int lineNumber = 0;

    // Open the input file
    file = fopen("input2.c", "r");

    // Check if the file exists
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Check if the line contains the word "double"
        if (strstr(line, "double") != NULL) {
            // Print the line number where double is found
            printf("double found on line %d\n", lineNumber);
        }
    }

    // Close the file
    fclose(file);

    return 0;
}

