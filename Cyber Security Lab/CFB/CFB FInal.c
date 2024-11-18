#include <bits/stdc++.h>
#include <vector>
#include <map>

std::string hex2Binary(const std::string& s) {
    std::map<char, std::string> hexToBinaryMap = {
        {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
        {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
        {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
        {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"}
    };

    std::string binary;
    for (char ch : s) {
        binary += hexToBinaryMap[ch];
    }
    return binary;
}

std::string binary2Hex(const std::string& s) {
    std::map<std::string, char> binaryToHexMap = {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };

    std::string hex;
    for (size_t i = 0; i < s.length(); i += 4) {
        std::string ch = s.substr(i, 4);
        hex += binaryToHexMap[ch];
    }
    return hex;
}

int binary2Decimal(int binary) {
    int binary1 = binary;
    int decimal = 0, i = 0;

    while (binary != 0) {
        int dec = binary % 10;
        decimal += dec * (1 << i);
        binary /= 10;
        i++;
    }

    return decimal;
}

std::string decimal2Binary(int num) {
    std::string binary = std::bitset<32>(num).to_string();

    if (binary.length() % 4 != 0) {
        int div = binary.length() / 4;
        int counter = (4 * (div + 1)) - binary.length();

        std::string paddedBinary(counter, '0');
        paddedBinary += binary;
        binary = paddedBinary;
    }

    return binary;
}

std::string permute(const std::string& k, const std::vector<int>& arr, int n) {
    std::string permutation;
    for (int i = 0; i < n; i++) {
        permutation += k[arr[i] - 1];
    }
    return permutation;
}

std::string shiftLeft(const std::string& k, int nthShifts) {
    std::string s = k;
    for (int shift = 0; shift < nthShifts; shift++) {
        s = s.substr(1) + s[0];
    }
    return s;
}

std::string xorStrings(const std::string& a, const std::string& b) {
    std::string result;
    for (size_t i = 0; i < a.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

std::vector<int> initialPermutation = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6,
                                      64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
                                      61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

std::vector<int> expansionPermutation = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17,
                                         18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};

std::vector<int> permutation = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13,
                                30, 6, 22, 11, 4, 25};
std::vector<int> finalPermutation = {
            40, 8, 48, 16, 56, 24, 64, 32,
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25
    };
std::vector<std::vector<std::vector<int>>> sBox = {
    {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
     {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
     {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
     {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
    {{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
     {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
     {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
     {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
      {{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
                    {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
                    {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
                    {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
            },
            {
                    {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
                    {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
                    {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
                    {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
            },
            {
                    {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
                    {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
                    {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
                    {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
            },
            {
                    {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
                    {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
                    {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
                    {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
            },
            {
                    {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
                    {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
                    {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
                    {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
            },
            {
                    {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
                    {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
                    {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
                    {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
            }
    };
    std::string encryptCFB(const std::string& pt, const std::vector<std::string>& rkb, const std::vector<std::string>& rk, const int sbox[8][4][16],
                       const int initialPermutation[64], const int expansionPermutation[48], const int permutation[32], const int finalPermutation[64], const std::string& iv) {
    std::string ciphertext = "";
    std::string currentIV = hex2Binary(iv);

    // Initial Permutation for IV
    currentIV = permute(currentIV, initialPermutation, 64);
    std::cout << "After initial permutation (IV): " << binary2Hex(currentIV) << std::endl;

    // Splitting IV into left and right parts
    std::string leftIV = currentIV.substr(0, 32);
    std::string rightIV = currentIV.substr(32, 32);

    // Splitting plaintext
    std::string left, right;

    for (size_t i = 0; i < pt.length(); i += 64) {
        left = leftIV;
        right = rightIV;

        for (size_t j = 0; j < 16; j++) {
            // Expansion D-box: Expanding the 32 bits data into 48 bits
            std::string rightExpanded = permute(right, expansionPermutation, 48);

            // XOR RoundKey[i] and right_expanded
            std::string xorX = xor(rightExpanded, rkb[j]);

            // S-boxes: substituting the value from s-box table by calculating row and column
            std::string sBoxStr = "";
            for (size_t k = 0; k < 8; k++) {
                int row = binary2Decimal(std::stoi(xorX.substr(k * 6, 1) + xorX.substr(k * 6 + 5, 1), nullptr, 2));
                int col = binary2Decimal(std::stoi(xorX.substr(k * 6 + 1, 1) + xorX.substr(k * 6 + 2, 3), nullptr, 2));
                int val = sbox[k][row][col];
                sBoxStr += decimal2Binary(val);
            }

            // Straight D-box: After substituting rearranging the bits
            sBoxStr = permute(sBoxStr, permutation, 32);

            // XOR leftIV and sBoxStr
            std::string result = xor(left, sBoxStr);
            left = result;

            // Swapper
            if (j != 15) {
                left = right;
                right = result;
            }

            std::cout << "Round " << (j + 1) << " " << binary2Hex(left) << " " << binary2Hex(right) << " " << rk[j] << std::endl;
        }

        // Combine and XOR with plaintext
        std::string combine = left + right;
        combine = xor(combine, pt.substr(i, 64));

        // Final permutation: final rearranging of bits to get ciphertext
        std::string ciphertextBlock = permute(combine, finalPermutation, 64);

        // Update IV for the next iteration
        leftIV = ciphertextBlock.substr(0, 32);
        rightIV = ciphertextBlock.substr(32, 32);

        std::cout << "Ciphertext Block: " << binary2Hex(ciphertextBlock) << std::endl;
        ciphertext += binary2Hex(ciphertextBlock);
    }

    return ciphertext;
}
std::string decryptCFB(const std::string &ct, const std::vector<std::string> &rkb, const std::vector<std::string> &rk, const std::vector<std::vector<std::vector<int>>> &sBox, const int initialPermutation[], const int expansionPermutation[], const int permutation[], const int finalPermutation[], const std::string &iv) {
    std::string ciphertext = hex2Binary(ct);

    // Initial Permutation for IV
    std::string ivBinary = hex2Binary(iv);
    std::string initialIV = permute(ivBinary, initialPermutation, 64);
    std::cout << "After initial permutation (IV): " << binary2Hex(initialIV) << std::endl;

    // Splitting IV into left and right parts
    std::string leftIV = initialIV.substr(0, 32);
    std::string rightIV = initialIV.substr(32, 32);

    // Splitting ciphertext
    std::string left, right;

    for (size_t i = 0; i < ciphertext.length(); i += 64) {
        // Perform DES encryption on IV
        for (int j = 0; j < 16; j++) {
            // Expansion D-box: Expanding the 32 bits data into 48 bits
            std::string rightIVExpanded = permute(rightIV, expansionPermutation, 48);

            // XOR RoundKey[i] and right_expanded
            std::string xorX = xor(rightIVExpanded, rkb[j]);

            // S-boxes: substituting the value from s-box table by calculating row and column
            std::string sBoxStr = "";
            for (int k = 0; k < 8; k++) {
                int row = binary2Decimal(std::stoi(xorX.substr(k * 6, 1) + xorX.substr(k * 6 + 5, 1), nullptr, 2));
                int col = binary2Decimal(std::stoi(xorX.substr(k * 6 + 1, 1) + xorX.substr(k * 6 + 2, 2) + xorX.substr(k * 6 + 4, 1), nullptr, 2));
                int val = sBox[k][row][col];
                sBoxStr += decimal2Binary(val);
            }

            // Straight D-box: After substituting rearranging the bits
            sBoxStr = permute(sBoxStr, permutation, 32);

            // XOR leftIV and sBoxStr
            std::string result = xor(leftIV, sBoxStr);
            leftIV = result;

            // Swapper
            if (j != 15) {
                leftIV = rightIV;
                rightIV = result;
            }

            std::cout << "Round " << (j + 1) << " " << binary2Hex(leftIV) << " " << binary2Hex(rightIV) << " " << rk[j] << std::endl;
        }

        // Combine and XOR with ciphertext
        std::string combine = leftIV + rightIV;
        combine = xor(combine, ciphertext.substr(i, 64));

        // Final permutation: final rearranging of bits to get plaintext
        std::string plaintextBlock = permute(combine, finalPermutation, 64);

        // Update IV for the next iteration
        leftIV = ciphertext.substr(i, 32);
        rightIV = ciphertext.substr(i + 32, 32);

        std::cout << "Plaintext Block: " << binary2Hex(plaintextBlock) << std::endl;
    }

    return binary2Hex(ciphertext);
}

int main() {
    std::string pt = "123456ABCD132536";
    std::string key = "AABB09182736CCDD";
    std::string iv = "0123456789ABCDEF"; // Initialization Vector

    // Key generation
    std::string keyBinary = hex2Binary(key);

    // Parity bit drop table
    int keyp[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
                    63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

    keyBinary = permute(keyBinary, keyp, 56);
     int shiftTable[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
    int keyComp[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,  41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

std::string left = keyBinary.substr(0, 28);
    std::string right = keyBinary.substr(28, 28);

    std::vector<std::string> rkb(16);
    std::vector<std::string> rk(16);

    for (int i = 0; i < 16; i++) {
        left = shiftLeft(left, shiftTable[i]);
        right = shiftLeft(right, shiftTable[i]);
        std::string combineStr = left + right;
        std::string roundKey = permute(combineStr, keyComp, 48);
        rkb[i] = roundKey;
        rk[i] = binary2Hex(roundKey);
    }

    // Encryption (CFB Mode)
    std::cout << "Encryption (CFB Mode)" << std::endl;
    std::string ciphertext = encryptCFB(pt, rkb, rk, sBox, initialPermutation, expansionPermutation, permutation, finalPermutation, iv);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    // Decryption (CFB Mode)
    std::cout << "\nDecryption (CFB Mode)" << std::endl;
    std::string decryptedText = decryptCFB(ciphertext, rkb, rk, sBox, initialPermutation, expansionPermutation, permutation, finalPermutation, iv);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
