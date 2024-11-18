#include <stdio.h>

// Encrypts text using a shift specified by the key
void encrypt(char plaintext[], int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            char encryptedChar = (char)(((ch + key - 'A' + 26) % 26) + 'A');
            printf("%c", encryptedChar);
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            char encryptedChar = (char)(((ch + key - 'a' + 26) % 26) + 'a');
            printf("%c", encryptedChar);
        }
        // Keep non-alphabetic characters unchanged
        else {
            printf("%c", ch);
        }
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    int key = 3;

    // Encrypt the plaintext
    printf("Original: %s\n", plaintext);
    printf("Encrypted: ");
    encrypt(plaintext, key);

    return 0;
}

