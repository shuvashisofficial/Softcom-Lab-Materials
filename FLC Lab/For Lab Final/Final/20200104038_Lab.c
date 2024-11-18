#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int integerCount = 0, voidCount = 0;

    // Open the input file
    file = fopen("Input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Check for function lines and count return types
        if (strstr(line, "int ") != NULL && strstr(line, "*") != NULL) {
            // This line defines a function

                integerCount++;

        }
    }

    // Close the file
    fclose(file);

    // Print the results
    printf("Integer: %d, \n", integerCount);

    return 0;
}
