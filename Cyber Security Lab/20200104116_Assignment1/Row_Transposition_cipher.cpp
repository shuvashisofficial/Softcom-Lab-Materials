#include<bits/stdc++.h>
using namespace std;

int main()
{
    string plaintext, key;

    cout << "Enter the plain text: ";
    cin >> plaintext;

    cout << "Enter the key: ";
    cin >> key;

    cout << "Plain text: " << plaintext << endl;
    //cout << "Key: " << key << endl;

    int keyLength = key.length();
    int textLength = plaintext.length();

    // Calculate the number of rows needed
    int numRows = textLength / keyLength;
    if (textLength % keyLength != 0)
    {
        numRows++;
    }

    // Create a 2D array to hold the plaintext in rows and columns
    char matrix[numRows][keyLength];

    // Fill the matrix with the plaintext
    int index = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < keyLength; j++)
        {
            if (index < textLength)
            {
                matrix[i][j] = plaintext[index++];
            }
            else
            {
                // If we run out of plaintext, fill the matrix with random characters
                matrix[i][j] = 'x';
            }
        }
    }

    // Print the matrix (optional)
    cout << "Matrix after encripted: " << endl;
    for (int i = 0; i<keyLength; i++)
    {
        cout << key[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < keyLength; j++)
        {
            int col = key[j] - '1';
            cout << matrix[i][col] << " ";
        }

        cout << endl;
    }

    // printing encryption message.
    cout << "Encrypted text: ";
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < keyLength; j++)
        {
            int col = key[j] - '1';
            cout << matrix[i][col];
        }
    }
    cout << endl;

    return 0;
}
//thesimplestpossibletranspositions
//41532
