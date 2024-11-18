#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
bool isStringValid(const char* str);

int main() {
    // Example usage with user input
    char input[1000];
    printf("Enter a string to check: ");
    scanf("%s", input);

    // Check if the input string is valid
    if (isStringValid(input)) {
        printf("The input string follows the grammar.\n");
    } else {
        printf("The input string does not follow the grammar.\n");
    }

    return 0;
}

bool isStringValid(const char* str) {
    // Check if the string follows the grammar rules
    int length = strlen(str);

    if (length < 3 || str[0] != 'a' || str[length - 1] != 'd') {
        return false;
    }

    for (int i = 1; i < length - 1; ++i) {
        if (str[i] == 'b') {
            if (i + 1 < length - 1 && str[i + 1] == 'b') {
                i++;
            } else {
                return false;
            }
        }
        else if (str[i] == 'a') {
            // Handle 'a' case
            if (i + 1 < length - 1 && str[i + 1] == 'b') {
                i++;
            } else {
                return false;
            }
        }
        else if (str[i] == 'b' && str[i + 1] == 'c') {
            // Handle 'bc' case
            if (i + 2 < length - 1 && str[i + 2] == 'b') {
                i += 2;
            } else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}



/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function declarations
char* generateString();
char* generateA();
char* generateX();
bool isStringValid(const char* str);

int main() {
    // Example usage with user input
    char input[1000];
    printf("Enter a string to check: ");
    scanf("%s", input);

    // Check if the input string is valid
    if (isStringValid(input)) {
        printf("The input string follows the grammar.\n");
    } else {
        printf("The input string does not follow the grammar.\n");
    }

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

bool isStringValid(const char* str) {
    // Check if the string follows the grammar rules
    int length = strlen(str);

    if (length < 3 || str[0] != 'a' || str[length - 1] != 'd') {
        return false;
    }

    for (int i = 1; i < length - 1; ++i) {
        if (str[i] == 'b') {
            if (i + 1 < length - 1 && str[i + 1] == 'b') {
                i++;
            } else {
                return false;
            }
        }
        else if (str[i] == 'b' && str[i + 1] == 'c') {
           if (i + 3 < length - 1 && str[i + 3] == 'b' && str[i + 4] == 'c') { //abcbcd
                i++;
            } else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}*/
