#include <iostream>
#include <string>

using namespace std;

string encryptRailFence(string plaintext, int numRows) {
    int len = plaintext.length();
    char railMatrix[numRows][len];

    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < len; ++j)
            railMatrix[i][j] = '\0';

    bool direction = false;
    int row = 0, col = 0;

    for (int i = 0; i < len; ++i) {
        if (row == 0 || row == numRows - 1)
            direction = !direction;

        railMatrix[row][col++] = plaintext[i];

        direction ? ++row : --row;
    }

    string ciphertext;
    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < len; ++j)
            if (railMatrix[i][j] != '\0')
                ciphertext.push_back(railMatrix[i][j]);

    return ciphertext;
}

int main() {
    string plaintext;
    int numRows;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the number of rows: ";
    cin >> numRows;

    string ciphertext = encryptRailFence(plaintext, numRows);

    cout << "Encrypted text: " << ciphertext << endl;

    return 0;
}
//meetmeafterthetogaparty
