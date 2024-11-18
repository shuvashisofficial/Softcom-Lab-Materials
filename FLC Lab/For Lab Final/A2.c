#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct data
{
    char sl[100];
    char idName[100];
    char idType[100];
    char idValue[100];
} v[100];

int c = 0;

void updateValue(char idTypeToFind[], char scopeToFind[], char newValue[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(v[i].idName, idTypeToFind) == 0 && strcmp(v[i].idType, scopeToFind) == 0)
        {
            c = 1;
            snprintf(v[i].idValue, sizeof(v[i].idValue), "%s", newValue);
            printf("\nUpdated value for ID Type '%s' and Scope '%s' to '%s'\n", idTypeToFind, scopeToFind, newValue);

            // Save the updated table to "symbol.txt"
            saveTableToFile("symbol.txt");

            return;
        }
    }

    printf("ID Type '%s' and Scope '%s' not found in the table.\n", idTypeToFind, scopeToFind);
}

void deleteEntry(char idTypeToFind[], char scopeToFind[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(v[i].idName, idTypeToFind) == 0 && strcmp(v[i].idType, scopeToFind) == 0)
        {
            c = 1;
            // Deleting the entry by setting empty strings
            v[i].sl[0] = '\0';
            v[i].idName[0] = '\0';
            v[i].idType[0] = '\0';
            v[i].idValue[0] = '\0';
            printf("\nDeleted entry for ID Type '%s' and Scope '%s'\n", idTypeToFind, scopeToFind);

            // Save the updated table to "symbol.txt"
            saveTableToFile("symbol.txt");

            return;
        }
    }

    printf("ID Type '%s' and Scope '%s' not found in the table.\n", idTypeToFind, scopeToFind);
}

void saveTableToFile(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%-5s%-10s%-10s%-10s\n", "ID", "ID Type", "Scope", "Value");
    for (int i = 0; i < 6; i++)
    {
        if (v[i].sl[0] != '\0')
        {
            fprintf(file, "%-5s%-10s%-10s%-10s\n", v[i].sl, v[i].idName, v[i].idType, v[i].idValue);
        }
    }

    fclose(file);
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
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

void insertEntry(char sl[], char idName[], char idType[], char idValue[])
{
    for (int i = 0; i < 6; i++)
    {
        if (v[i].sl[0] == '\0')
        {
            snprintf(v[i].sl, sizeof(v[i].sl), "%s", sl);
            snprintf(v[i].idName, sizeof(v[i].idName), "%s", idName);
            snprintf(v[i].idType, sizeof(v[i].idType), "%s", idType);
            snprintf(v[i].idValue, sizeof(v[i].idValue), "%s", idValue);

            // Save the updated table to "symbol.txt"
            saveTableToFile("symbol.txt");

            printf("\nInserted entry for ID Type '%s' and Scope '%s' with value '%s'\n", idName, idType, idValue);
            return;
        }
    }

    printf("Table is full. Cannot insert new entry.\n");
}

int main()
{
    // Inserting values into the structure
    snprintf(v[0].sl, sizeof(v[0].sl), "1");
    snprintf(v[0].idName, sizeof(v[0].idName), "x1");
    snprintf(v[0].idType, sizeof(v[0].idType), "global");
    snprintf(v[0].idValue, sizeof(v[0].idValue), "4.6");

    snprintf(v[1].sl, sizeof(v[1].sl), "2");
    snprintf(v[1].idName, sizeof(v[1].idName), "f1");
    snprintf(v[1].idType, sizeof(v[1].idType), "global");
    snprintf(v[1].idValue, sizeof(v[1].idValue), "null");

    snprintf(v[2].sl, sizeof(v[2].sl), "3");
    snprintf(v[2].idName, sizeof(v[2].idName), "x");
    snprintf(v[2].idType, sizeof(v[2].idType), "f1");
    snprintf(v[2].idValue, sizeof(v[2].idValue), "2.6");

    snprintf(v[3].sl, sizeof(v[3].sl), "4");
    snprintf(v[3].idName, sizeof(v[3].idName), "main");
    snprintf(v[3].idType, sizeof(v[3].idType), "global");
    snprintf(v[3].idValue, sizeof(v[3].idValue), "null");

    snprintf(v[4].sl, sizeof(v[4].sl), "5");
    snprintf(v[4].idName, sizeof(v[4].idName), "x");
    snprintf(v[4].idType, sizeof(v[4].idType), "main");
    snprintf(v[4].idValue, sizeof(v[4].idValue), "70");

    // Save the table to "symbol.txt"
    saveTableToFile("symbol.txt");
    readTableFromFile("symbol.txt");

    // Update the value for idType "x" and scope "main" to "100" (from the file)
    updateValue("x", "main", "100");
    printf("\nReading updated table from %s:", "symbol.txt");
    readTableFromFile("symbol.txt");

    // Delete the entry for idType "f1" and scope "global"
    //deleteEntry("f1", "global");
    //printf("\nReading table after deletion from %s:", "symbol.txt");
    //readTableFromFile("symbol.txt");

    // Insert a new entry with ID Type "y", Scope "main", and value "100"
    insertEntry("6", "y", "main", "100");
    printf("\nReading table after insertion from %s:", "symbol.txt");
    readTableFromFile("symbol.txt");

    // Try to update a non-existent entry
    updateValue("z", "main", "200");

    // Try to delete a non-existent entry
    deleteEntry("z", "xyz");

}
