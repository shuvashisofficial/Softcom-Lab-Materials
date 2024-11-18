#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct Symbol {
    int slNo;
    char idName[MAX_LEN];
    char idType[MAX_LEN];
    float idValue;
};

void updateSymbolValue(struct Symbol symbolTable[], int n, char variable[], char scope[], float newValue) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(symbolTable[i].idName, variable) == 0 && strcmp(symbolTable[i].idType, scope) == 0) {
            symbolTable[i].idValue = newValue;
            return;
        }
    }
    printf("Variable not found in symbol table\n");
}

void displaySymbolTable(struct Symbol symbolTable[], int n) {
    printf("The Symbol table:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%s\t%s\t%.2f\n", symbolTable[i].slNo, symbolTable[i].idName, symbolTable[i].idType, symbolTable[i].idValue);
    }
}

int main() {
    FILE *file = fopen("SymbolTable.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    struct Symbol symbolTable[n];

    for (int i = 0; i < n; ++i) {
        fscanf(file, "%d %s %s %f", &symbolTable[i].slNo, symbolTable[i].idName, symbolTable[i].idType, &symbolTable[i].idValue);
    }

    fclose(file);

    displaySymbolTable(symbolTable, n);

    char variable[MAX_LEN], scope[MAX_LEN];
    float newValue;

    printf("\nEnter variable, scope, and new value: ");
    scanf("%s %s %f", variable, scope, &newValue);

    updateSymbolValue(symbolTable, n, variable, scope, newValue);

    printf("\nThe updated Symbol table:\n");
    displaySymbolTable(symbolTable, n);

    return 0;
}
