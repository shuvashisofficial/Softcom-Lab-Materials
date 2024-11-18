#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isIdentifier(char *str) {
    if (!(isalpha(str[0]) || str[0] == '_')){
         return 0;
}
    for (int i = 1; i < strlen(str); i++){
        if (!(isalpha(str[i]) || str[i] == '_' || isdigit(str[i]))) {
            return 0;
        }
    }
    return 1;
    }
int main() {
    char identifier[50];

    // Get input from the user
    printf("Enter a string: ");
    scanf("%s", identifier);

    // Check if the entered string is a valid identifier
    if (isIdentifier(identifier)) {
        printf("%s is a valid identifier.\n", identifier);
    } else {
        printf("%s is not a valid identifier.\n", identifier);
    }

    return 0;
}
