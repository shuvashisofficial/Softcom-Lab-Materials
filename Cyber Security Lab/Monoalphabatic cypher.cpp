#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Encrypts text using a substitution cipher
void encrypt(char plaintext[], char substitutionKey[]) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Encrypt only alphabetical characters
        if (isalpha(ch)) {
            char encryptedChar;
            if (isupper(ch)) {
                encryptedChar = substitutionKey[ch - 'A'];
            } else {
                encryptedChar = tolower(substitutionKey[toupper(ch) - 'A']);
            }
            printf("%c", encryptedChar);
        } else {
            printf("%c", ch);
        }
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    char substitutionKey[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

    // Encrypt the plaintext
    printf("Original: %s\n", plaintext);
    printf("Encrypted: ");
    encrypt(plaintext, substitutionKey);

    return 0;
}
