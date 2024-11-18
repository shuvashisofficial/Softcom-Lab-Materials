#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *file;
    char line[256];
    int lineNumber = 0;
    file = fopen("input1.c", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    printf("Line No. of output functions: ");
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
        if (strstr(line, "printf") != NULL) {
            printf("%d ", lineNumber);
        }
    }
    fclose(file);

    return 0;
}

