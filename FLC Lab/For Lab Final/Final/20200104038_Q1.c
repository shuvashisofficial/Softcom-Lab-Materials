#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int integerCount = 0, voidCount = 0;


    file = fopen("Input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }


    while (fgets(line, sizeof(line), file)) {

        if (strstr(line, "int ") != NULL && strstr(line, "*") != NULL ) {


                integerCount++;

        }
    }


    fclose(file);


    printf("Integer: %d\n", integerCount);

    return 0;
}
