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

void deleteSymbol(struct Symbol symbolTable[], int *n, char variable[], char scope[]) {
    int foundIndex = -1;
    for (int i = 0; i < *n; ++i) {
        if (strcmp(symbolTable[i].idName, variable) == 0 && strcmp(symbolTable[i].idType, scope) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        // Delete the symbol by shifting elements
        for (int i = foundIndex; i < *n - 1; ++i) {
            symbolTable[i] = symbolTable[i + 1];
        }
        (*n)--;
        printf("Variable deleted from symbol table\n");
    } else {
        printf("Variable not found in symbol table\n");
    }
}

void displaySymbolTable(struct Symbol symbolTable[], int n) {
    printf("The Symbol table:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%s\t%s\t%.2f\n", symbolTable[i].slNo, symbolTable[i].idName, symbolTable[i].idType, symbolTable[i].idValue);
    }
}

void writeSymbolTable(struct Symbol symbolTable[], int n) {
    FILE *fp = fopen("SymbolTable.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }

    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%d %s %s %.2f\n", symbolTable[i].slNo, symbolTable[i].idName, symbolTable[i].idType, symbolTable[i].idValue);
    }

    fclose(fp);
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

    // Deleting a symbol
    printf("\nEnter variable : ");
    scanf("%s", variable);
    printf("\nEnter scope : ");
    scanf("%s", scope);
    deleteSymbol(symbolTable, &n, variable, scope);

    printf("\nThe updated Symbol table after deletion:\n");
    displaySymbolTable(symbolTable, n);
    writeSymbolTable(symbolTable, n);  // Writing the updated table to file

    return 0;
}
