#include <bits/stdc++.h>
using namespace std;
void findDoubleDeclarations(FILE *file) {
    char line[256];
    int lineNumber = 0;
    cout<<"Line No. of output function:";
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Check if the line contains the declaration of double variables
        if (strstr(line, "double") != NULL) {
            printf("Line %d %s", lineNumber, line);
            printf("\n");
        }
    }
}

int main() {
    FILE *fp = fopen("input3.txt", "r");

    if (fp == NULL) {
        printf("File not found or cannot be opened.");
        return 1;
    }

    findDoubleDeclarations(fp);

    fclose(fp);
    return 0;
}

