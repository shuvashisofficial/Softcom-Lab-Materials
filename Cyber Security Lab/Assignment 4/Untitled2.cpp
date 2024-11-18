#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

const int COLS = 8;

vector<int> arrayresult(64);
vector<int> arrayresult2(64);
vector<int> initialpermutation = {
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7,
    56, 48, 40, 32, 24, 16, 8, 0,
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6
};

vector<int> inverseinitialpermutation = {
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25,
    32, 0, 40, 8, 48, 16, 56, 24
};

vector<int> pc1 = {
    57, 49, 41, 33, 25, 17, 9,
    1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27,
    19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
    7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29,
    21, 13, 5, 28, 20, 12,4
};

vector<int> pc2 = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

vector<int> numberOfShifts = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

vector<int> ebitselection = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32

};

vector<int> pbox = {
    16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25
};

// S-boxes (8 S-boxes, each with 4 rows and 16 columns)
vector<int> sboxes[8] = {
    // S-box 1
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
     0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
     4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
     15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},

    // S-box 2
    {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
     3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
     0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
     13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},

    // S-box 3
    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
     13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
     13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
     1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},

    // S-box 4
    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
     13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
     10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
     3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},

    // S-box 5
    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
     14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
     4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
     11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},

    // S-box 6
    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
     10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
     9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
     4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},

    // S-box 7
    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
     13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
     1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
     6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},

    // S-box 8
    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
     1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
     7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
     2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
};


vector<int> straightpbox = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

map<char, bitset<8>> hexToBinary = {
    {'0', bitset<8>("0000")},
    {'1', bitset<8>("0001")},
    {'2', bitset<8>("0010")},
    {'3', bitset<8>("0011")},
    {'4', bitset<8>("0100")},
    {'5', bitset<8>("0101")},
    {'6', bitset<8>("0110")},
    {'7', bitset<8>("0111")},
    {'8', bitset<8>("1000")},
    {'9', bitset<8>("1001")},
    {'A', bitset<8>("1010")},
    {'B', bitset<8>("1011")},
    {'C', bitset<8>("1100")},
    {'D', bitset<8>("1101")},
    {'E', bitset<8>("1110")},
    {'F', bitset<8>("1111")}
};

// Function to perform initial permutation
vector<int> initialPermutation(const vector<int>& input) {
    vector<int> result(64);
    for (int i = 0; i < 64; ++i) {
        result[i] = input[initialpermutation[i]];
    }
    return result;
}

// Function to perform inverse initial permutation
vector<int> inverseInitialPermutation(const vector<int>& input) {
    vector<int> result(64);
    for (int i = 0; i < 64; ++i) {
        result[i] = input[inverseinitialpermutation[i]];
    }
    return result;
}

// Function to perform circular left shift
vector<int> circularLeftShift(const vector<int>& input, int shift) {
    vector<int> result(input.size());
    for (int i = 0; i < 28; ++i) {
        int shiftedIndex = (i + shift) % 28;
        result[i] = input[shiftedIndex];
    }
    return result;
}

// Function to perform PC1 permutation
vector<int> pc1Permutation(const vector<int>& input) {
    vector<int> result(56);
    for (int i = 0; i < 56; ++i) {
        result[i] = input[pc1[i]];
    }
    return result;
}

// Function to perform PC2 permutation
vector<int> pc2Permutation(const vector<int>& input) {
    vector<int> result(48);
    for (int i = 0; i < 48; ++i) {
        result[i] = input[pc2[i]];
    }
    return result;
}

// Function to perform expansion permutation (E-box)
vector<int> expansionPermutation(const vector<int>& input) {
    vector<int> result(48);
    for (int i = 0; i < 48; ++i) {
        result[i] = input[ebitselection[i]];
    }
    return result;
}

// Function to perform P-box permutation
vector<int> pBoxPermutation(const vector<int>& input) {
    vector<int> result(32);
    for (int i = 0; i < 32; ++i) {
        result[i] = input[pbox[i]];
    }
    return result;
}

// Function to perform straight P-box permutation
vector<int> straightPBoxPermutation(const vector<int>& input) {
    vector<int> result(64);
    for (int i = 0; i < 64; ++i) {
        result[i] = input[straightpbox[i]];
    }
    return result;
}

// Function to perform S-box substitution
vector<int> sBoxSubstitution(const vector<int>& input) {
    vector<int> result;
    // Divide the 48 bits into 8 groups of 6 bits
    for (int i = 0; i < 48; i += 6) {
        int row = (input[i] << 1) + input[i + 5];
        int col = (input[i + 1] << 3) + (input[i + 2] << 2) + (input[i + 3] << 1) + input[i + 4];
        int value = sboxes[i / 6][row * 16 + col];
        // Convert the 4-bit value to binary
        bitset<4> bits(value);
        // Append the 4 bits to the result
        for (int j = 3; j >= 0; --j) {
            result.push_back(bits[j]);
        }
    }
    return result;
}

// Function to convert hexadecimal to binary
vector<int> hexToBinaryVector(const string& hex) {
    vector<int> result;
    for (char c : hex) {
        bitset<8> bits = hexToBinary[c];
        // Append the 8 bits to the result
        for (int i = 7; i >= 0; --i) {
            result.push_back(bits[i]);
        }
    }
    return result;
}
string binaryToHex(const vector<int>& binary) {
    string result;
    // Convert binary to hexadecimal in groups of 4 bits
    for (size_t i = 0; i < binary.size(); i += 4) {
        int decimal = 0;
        // Convert 4 bits to decimal
        for (size_t j = 0; j < 4; ++j) {
            decimal = (decimal << 1) + binary[i + j];
        }
        // Convert decimal to hexadecimal
        result += (decimal < 10) ? ('0' + decimal) : ('A' + decimal - 10);
    }
    return result;
}

// Function to perform Feistel network
vector<int> feistel(const vector<int>& right, const vector<int>& subkey) {
    // Expansion permutation (E-box)
    vector<int> expanded = expansionPermutation(right);

    // XOR with subkey
    for (size_t i = 0; i < expanded.size(); ++i) {
        expanded[i] ^= subkey[i];
    }

    // S-box substitution
    vector<int> substituted = sBoxSubstitution(expanded);

    // P-box permutation
    vector<int> result = pBoxPermutation(substituted);

    return result;
}

// Function to perform encryption for a single round
pair<vector<int>, vector<int>> singleRound(const vector<int>& left, const vector<int>& right, const vector<int>& subkey) {
    // Feistel function
    vector<int> fResult = feistel(right, subkey);

    // XOR with left half
    vector<int> xorResult;
    for (size_t i = 0; i < left.size(); ++i) {
        xorResult.push_back(left[i] ^ fResult[i]);
    }

    // Swap left and right halves
    return make_pair(right, xorResult);
}

// Function to generate subkeys
vector<vector<int>> generateSubkeys(const vector<int>& key) {
    vector<vector<int>> subkeys;
    // Perform PC1 permutation
    vector<int> pc1Result = pc1Permutation(key);

    // Split into left and right halves
    vector<int> left(pc1Result.begin(), pc1Result.begin() + 28);
    vector<int> right(pc1Result.begin() + 28, pc1Result.end());

    // Generate subkeys for each round
    for (int i = 0; i < 16; ++i) {
        // Perform circular left shift
        left = circularLeftShift(left, numberOfShifts[i]);
        right = circularLeftShift(right, numberOfShifts[i]);

        // Concatenate left and right
        vector<int> combined = left;
        combined.insert(combined.end(), right.begin(), right.end());

        // Perform PC2 permutation
        vector<int> subkey = pc2Permutation(combined);

        // Add subkey to the list
        subkeys.push_back(subkey);
    }

    return subkeys;
}
void printBinary(const vector<int>& block, const string& label) {
    cout << label << ": ";
    for (int bit : block) {
        cout << bit;
    }
    cout << endl;
}
vector<int> permute(const vector<int>& block, const vector<int>& permutationTable) {
    vector<int> result;
    for (int index : permutationTable) {
        result.push_back(block[index - 1]);
    }
    return result;
}

// Function to perform XOR operation on two blocks of data
vector<int> xorBlocks(const vector<int>& block1, const vector<int>& block2) {
    vector<int> result;
    for (size_t i = 0; i < block1.size(); ++i) {
        result.push_back(block1[i] ^ block2[i]);
    }
    return result;
}

// Function to substitute using S-boxes
vector<int> substitute(const vector<int>& block) {
    vector<int> result;
    for (int i = 0; i < 48; i += 6) {
        int row = block[i] * 2 + block[i + 5];
        int col = block[i + 1] * 8 + block[i + 2] * 4 + block[i + 3] * 2 + block[i + 4];
        int value = sboxes[i / 6][row][col];
        bitset<4> bits(value);
        for (int j = 3; j >= 0; --j) {
            result.push_back(bits[j]);
        }
    }
    return result;
}

// Function to print the state of the data at each step of encryption
void printEncryptionSteps(const vector<int>& data, const vector<vector<int>>& subkeys) {
    vector<int> left = {data.begin(), data.begin() + 32};
    vector<int> right = {data.begin() + 32, data.end()};

    cout << "Initial Data:" << endl;
    printBinary(left, "Left");
    printBinary(right, "Right");
    cout << endl;

    for (int round = 0; round < 16; ++round) {
        cout << "Round " << round + 1 << ":" << endl;

        // Expansion permutation
        vector<int> expandedRight = permute(right, expansionPermutation);

        // XOR with round key
        vector<int> roundKey = subkeys[round];
        vector<int> xorResult = xorBlocks(expandedRight, roundKey);

        // Substitution using S-boxes
        vector<int> substitutionResult = substitute(xorResult);

        // Permutation
        vector<int> permutationResult = permute(substitutionResult, permutation);

        // XOR with left half
        vector<int> newRight = xorBlocks(left, permutationResult);

        // Update left and right halves for the next round
        left = right;
        right = newRight;

        // Print the intermediate state
        printBinary(left, "Left");
        printBinary(right, "Right");
        cout << endl;
    }
}

int main() {
    // Example key and plaintext
    string hexKey = "133457799BBCDFF1";
    string hexPlaintext = "0123456789ABCDEF";

    // Convert key and plaintext to binary
    vector<int> key = hexToBinaryVector(hexKey);
    vector<int> plaintext = hexToBinaryVector(hexPlaintext);

    // Generate subkeys
    vector<vector<int>> subkeys = generateSubkeys(key);

    // Initial permutation of the plaintext
    vector<int> permutedPlaintext = initialPermutation(plaintext);

    // Split into left and right halves
    vector<int> left(permutedPlaintext.begin(), permutedPlaintext.begin() + 32);
    vector<int> right(permutedPlaintext.begin() + 32, permutedPlaintext.end());

    // 16 rounds of encryption
    for (int i = 0; i < 16; ++i) {
        // Perform a single round
        pair<vector<int>, vector<int>> roundResult = singleRound(left, right, subkeys[i]);
        left = roundResult.first;
        right = roundResult.second;
    }

    // Combine left and right halves
    vector<int> combinedResult = left;
    combinedResult.insert(combinedResult.end(), right.begin(), right.end());

    // Final permutation
    vector<int> encryptedResult = inverseInitialPermutation(combinedResult);

    // Convert the encrypted result to hexadecimal
    string hexResult = binaryToHex(encryptedResult);

        vector<int> encryptedData = desEncrypt(data, subkeys);

    // Print the final encrypted data
    cout << "Final Encrypted Data:" << endl;
    printBinary(encryptedData, "");

    // Print all 16 steps of encryption
    cout << endl << "Encryption Steps:" << endl;
    printEncryptionSteps(data, subkeys);

    return 0;
}
// Function to convert binary to hexadecimal
