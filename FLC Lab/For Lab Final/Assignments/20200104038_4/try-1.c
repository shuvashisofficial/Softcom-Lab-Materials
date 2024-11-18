#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
char* generateString();
char* generateA();
char* generateX();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Example usage
    char* generatedString = generateString();
    printf("%s\n", generatedString);

    // Don't forget to free allocated memory
    free(generatedString);

    return 0;
}

char* generateString() {
    char* result = generateA();
    return result;
}

char* generateA() {
    char* result = (char*)malloc(1000); // Assuming a maximum length of 1000 characters, adjust as needed
    sprintf(result, "a%sd", generateX());
    return result;
}

char* generateX() {
    int choice = rand() % 3 + 1;

    if (choice == 1) {
        char* result = (char*)malloc(1000);
        sprintf(result, "bb%s", generateX());
        return result;
    } else if (choice == 2) {
        char* result = (char*)malloc(1000);
        sprintf(result, "bc%s", generateX());
        return result;
    } else {
        char* result = (char*)malloc(1);
        result[0] = '\0';  // epsilon
        return result;
    }
}

