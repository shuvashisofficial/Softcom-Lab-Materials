#include <stdio.h>
#include <string.h>

// Function to perform encryption using row transposition cipher
void encrypt(char plaintext[], char key[]) {
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);

    // Calculate the number of rows needed
    int numRows = textLength / keyLength;
    if (textLength % keyLength != 0) {
        numRows++;
    }

    // Create a 2D array to hold the plaintext in rows and columns
    char matrix[numRows][keyLength];

    // Fill the matrix with the plaintext
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLength; j++) {
            if (index < textLength) {
                matrix[i][j] = plaintext[index++];
            } else {
                // If we run out of plaintext, fill the matrix with random characters
                matrix[i][j] = 'X';
            }
        }
    }

    // Print the matrix (optional)
    printf("Matrix after filling:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLength; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Encrypt the plaintext by reading the matrix row-wise based on the key
    printf("Encrypted text: ");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < keyLength; j++) {
            int col = key[j] - '1';
            printf("%c", matrix[i][col]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[] = "HELLOWORLD";
    char key[] = "321";

    printf("Original text: %s\n", plaintext);

    encrypt(plaintext, key);

    return 0;
}
