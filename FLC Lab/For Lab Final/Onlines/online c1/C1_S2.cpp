#include <bits/stdc++.h>
using namespace std;

void findOutputFunctions(FILE *file) {
    char line[256];
    int lineNumber = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Check if the line contains the output function (e.g., printf)

        if (strstr(line, "printf") != NULL) {
            printf("%d ", lineNumber);
        }
    }
}

int main() {
    FILE *fp = fopen("input2.txt", "r");

    if (fp == NULL) {
        printf("File not found or cannot be opened.");
        return 1;
    }

    findOutputFunctions(fp);

    fclose(fp);
    return 0;
}
