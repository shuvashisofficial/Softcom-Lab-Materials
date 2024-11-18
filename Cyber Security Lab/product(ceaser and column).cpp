#include <stdio.h>
#include <string.h>

// Function to perform Caesar substitution encryption
void caesarEncrypt(char plaintext[], int shift) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

// Function to perform columnar transposition encryption
void columnarEncrypt(char plaintext[], char key[]) {
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);

    // Calculate the number of columns needed
    int numColumns = keyLength;

    // Calculate the number of rows needed
    int numRows = textLength / numColumns;
    if (textLength % numColumns != 0) {
        numRows++;
    }

    // Create a 2D array to hold the plaintext in rows and columns
    char matrix[numRows][numColumns];

    // Fill the matrix with the plaintext
    int index = 0;
    for (int j = 0; j < numRows; j++) {
        for (int i = 0; i < numColumns; i++) {
            if (index < textLength) {
                matrix[j][i] = plaintext[index++];
            } else {
                // If we run out of plaintext, fill the matrix with random characters
                matrix[j][i] = 'X';
            }
        }
    }

    // Print the matrix
    printf("Matrix after filling:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Encrypt the plaintext by reading the matrix column-wise based on the key
    printf("Encrypted text: ");
    for (int i = 0; i < numColumns; i++) {
        int col = key[i] - '1';
        for (int j = 0; j < numRows; j++) {
            printf("%c", matrix[j][col]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[] = "HELLOWORLD";
    int shift = 3;
    char key[] = "321";

    printf("Original text: %s\n", plaintext);

    // Step 1: Caesar substitution encryption
    caesarEncrypt(plaintext, shift);
    printf("After Caesar substitution: %s\n", plaintext);

    // Step 2: Columnar transposition encryption
    columnarEncrypt(plaintext, key);

    return 0;
}
