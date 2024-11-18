#include<bits/stdc++.h>
using namespace std;

void encrypt(string plaintext, string key) {
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
                matrix[j][i] = 'x';
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
    string plaintext;
    string key;

    cout << "Plain Text: ";
    cin >> plaintext;

    cout << "Key: ";
    cin >> key;

    //converting key to number form.
    int len = key.length();
    string key2;
    char numberKey[len+1];

    key2 = key;

    sort(key2.begin(), key2.end());

    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(key2[i]==key[j])
            {
                numberKey[j] = (i) + '1';
            }
        }
    }

    cout << "Original text: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Key in number: " << numberKey << endl;

    encrypt(plaintext, numberKey);

    return 0;
}
//meetmeaftertheparty
//3124
