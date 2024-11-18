#include <iostream>
#include <string>

using namespace std;

void encrypt(const string& plaintext, const string& key) {
    int keyLength = key.length();
    int textLength = plaintext.length();

    // Calculate the number of columns needed
    int numColumns = keyLength;

    // Calculate the number of rows needed
    int numRows = textLength / numColumns;
    if (textLength % numColumns != 0) {
        numRows++;
    }

    char matrix[100][100]; // Assuming a maximum size, adjust as needed

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

    // Print the matrix (optional)
    cout << "Matrix after filling:" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Encrypt the plaintext by reading the matrix column-wise based on the key numbers
    cout << "Encrypted text: ";
    for (int k = 1; k <= keyLength; k++) {
        for (int i = 0; i < numColumns; i++) {
            if (key[i] - '0' == k) {
                for (int j = 0; j < numRows; j++) {
                    cout << matrix[j][i];
                }
            }
        }
    }
    cout << endl;
}

int main() {
    string plaintext = "meetmeaftertheparty";
    string key = "3124";

    cout << "Original text: " << plaintext << endl;

    encrypt(plaintext, key);

    return 0;
}
