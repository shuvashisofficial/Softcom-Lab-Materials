//online-1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    FILE *file1;
    char CodeL[100];
    char c;
    int intC = 0, VoidC = 0;

    file = fopen("input.txt", "r");
    file1 = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
     while ((c = getc(file1)) != EOF)
     {
         printf("%c", c);
     }

    while (fgets(CodeL, sizeof(CodeL), file)) {

        if (strstr(CodeL, "int ") != NULL && strstr(CodeL, "(") != NULL && strstr(CodeL, ")") != NULL) {
            if (strstr(CodeL, "void ") != NULL) {
                VoidC++;

            } else {
                intC++;
            }
        }else if (strstr(CodeL, "void ") != NULL && strstr(CodeL, "(") != NULL && strstr(CodeL, ")") != NULL) {
             if (strstr(CodeL, "void ") != NULL) {
                VoidC++;

            } else {
                intC++;
            }
        }
    }

    fclose(file);

    printf("Return Type      Counts\n");
    printf("Integer: %d\n", intC);
    printf("void: %d", VoidC);

    return 0;
}
