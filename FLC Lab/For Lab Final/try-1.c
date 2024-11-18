#include <stdio.h>
#include <stdbool.h>

struct data
{
    char id[100];
    char idType[100];
    char scope[100];
    char value[100];
} v[100];

void updateValue(char idTypeToFind[], char scopeToFind[], char newValue[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(v[i].idType, idTypeToFind) == 0 && strcmp(v[i].scope, scopeToFind) == 0)
        {
            snprintf(v[i].value, sizeof(v[i].value), "%s", newValue);
            printf("Updated value for ID Type '%s' and Scope '%s' to '%s'\n", idTypeToFind, scopeToFind, newValue);
            return;
        }
    }

    printf("ID Type '%s' and Scope '%s' not found in the table.\n", idTypeToFind, scopeToFind);
}
void insertEntry(char newID[], char newIDType[], char newScope[], char newValue[])
{
    // Check if there is space in the array
    if (sizeof(v) / sizeof(v[0]) < 100)
    {
        // Find the first available index
        int i = 0;
        while (v[i].id[0] != '\0')
        {
            i++;
        }

        // Insert the new entry
        snprintf(v[i].id, sizeof(v[i].id), "%s", newID);
        snprintf(v[i].idType, sizeof(v[i].idType), "%s", newIDType);
        snprintf(v[i].scope, sizeof(v[i].scope), "%s", newScope);
        snprintf(v[i].value, sizeof(v[i].value), "%s", newValue);

        printf("Inserted new entry: ID '%s' ID Type '%s' Scope '%s' Value '%s'\n", newID, newIDType, newScope, newValue);
    }
    else
    {
        printf("No space available for new entry.\n");
    }
}
void deleteEntry(char idTypeToDelete[], char scopeToDelete[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(v[i].idType, idTypeToDelete) == 0 && strcmp(v[i].scope, scopeToDelete) == 0)
        {
            // Move elements after the index to fill the gap
            for (int j = i; j < 4; j++)
            {
                strcpy(v[j].id, v[j + 1].id);
                strcpy(v[j].idType, v[j + 1].idType);
                strcpy(v[j].scope, v[j + 1].scope);
                strcpy(v[j].value, v[j + 1].value);
            }

            printf("Entry with ID Type '%s' and Scope '%s' deleted successfully.\n", idTypeToDelete, scopeToDelete);
            return;
        }
    }

    printf("ID Type '%s' and Scope '%s' not found in the table.\n", idTypeToDelete, scopeToDelete);
}

void searchEntry(char idTypeToFind[], char scopeToFind[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(v[i].idType, idTypeToFind) == 0 && strcmp(v[i].scope, scopeToFind) == 0)
        {
            printf("Found entry for ID Type '%s' and Scope '%s':\n", idTypeToFind, scopeToFind);
            printf("%-5s%-10s%-10s%-10s\n", "ID", "IDType", "Scope", "Value");
            printf("%-5s%-10s%-10s%-10s\n", v[i].id, v[i].idType, v[i].scope, v[i].value);
            return;
        }
    }

    printf("Entry for ID Type '%s' and Scope '%s' not found in the table.\n", idTypeToFind, scopeToFind);
}

void saveTableToFile(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%-5s%-10s%-10s%-10s\n", "ID", "IDType", "Scope", "Value");
    for (int i = 0; i < 5; i++)
    {
        fprintf(file, "%-5s%-10s%-10s%-10s\n", v[i].id, v[i].idType, v[i].scope, v[i].value);
    }

    fclose(file);

    printf("Table saved to %s\n", filename);
}

void readTableFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("\nReading table from %s:\n", filename);

    char line[400]; // Adjust the size based on your actual requirements

    // Read and print header
    if (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    // Read and print data
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "%s %s %s %s", v[i].id, v[i].idType, v[i].scope, v[i].value);
        printf("%-5s%-10s%-10s%-10s\n", v[i].id, v[i].idType, v[i].scope, v[i].value);
        i++;
    }

    fclose(file);
}

int main()
{
    // Read the initial table from "symbol.txt"
    readTableFromFile("symbol.txt");

    // Update the value for idType "x" and scope "main" to "100"
    updateValue("x", "main", "100");

    insertEntry("6", "era", "global", "100");

     deleteEntry("f1", "global");
    // Save the updated table to "updatedSymbolTable.txt"
    saveTableToFile("updatedSymbolTable.txt");

    // Display the updated table
    printf("\nUpdated Table:\n");
    readTableFromFile("updatedSymbolTable.txt");

    searchEntry("x", "main");
    searchEntry("f1", "global");

    return 0;
}
