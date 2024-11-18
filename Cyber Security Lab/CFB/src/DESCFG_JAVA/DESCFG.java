
package DESCFG_JAVA;

import java.util.Arrays;

public class DESCFG {
    public static int[] arrayresult = new int[64];
    public static int[] arrayresult2 = new int[64];

    public static  int[] initialPermutation = {
            57, 49, 41, 33, 25, 17, 9, 1,
            59, 51, 43, 35, 27, 19, 11, 3,
            61, 53, 45, 37, 29, 21, 13, 5,
            63, 55, 47, 39, 31, 23, 15, 7,
            56, 48, 40, 32, 24, 16, 8, 0,
            58, 50, 42, 34, 26, 18, 10, 2,
            60, 52, 44, 36, 28, 20, 12, 4,
            62, 54, 46, 38, 30, 22, 14, 6
    };

    public static int[] inverseInitialPermutation = {
            39, 7, 47, 15, 55, 23, 63, 31,
            38, 6, 46, 14, 54, 22, 62, 30,
            37, 5, 45, 13, 53, 21, 61, 29,
            36, 4, 44, 12, 52, 20, 60, 28,
            35, 3, 43, 11, 51, 19, 59, 27,
            34, 2, 42, 10, 50, 18, 58, 26,
            33, 1, 41, 9, 49, 17, 57, 25,
            32, 0, 40, 8, 48, 16, 56, 24
    };

    public static int[] pc1 = {
            57, 49, 41, 33, 25, 17, 9,
            1, 58, 50, 42, 34, 26, 18,
            10, 2, 59, 51, 43, 35, 27,
            19, 11, 3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14, 6, 61, 53, 45, 37, 29,
            21, 13, 5, 28, 20, 12, 4
    };

    public static int[] pc2 = {
            14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32
    };

    public static int[] numberOfShifts = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

     public static int[] eBitSelection = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
    };

    public static int[] pBox = {
            16, 7, 20, 21, 29, 12, 28, 17,
            1, 15, 23, 26, 5, 18, 31, 10,
            2, 8, 24, 14, 32, 27, 3, 9,
            19, 13, 30, 6, 22, 11, 4, 25
    };

    /**
     *
     */
public static int[] permutation = {
    15, 6, 19, 20,
    28, 11, 27, 16,
    0, 14, 22, 25,
    4, 17, 30, 9,
    1, 7, 23, 13,
    31, 26, 2, 8,
    18, 12, 29, 5,
    21, 10, 3, 24
};
    public static int[][][] sBox = {
            {
                    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
                    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
                    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
                    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
            },
        {  {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
    {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
    {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
    {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
},
        {
    {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
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

            // Repeat 7 more times for sBox2 to sBox8
};

    public static void main(String[] args) {
        // Example usage:
        int[] key = hexStringToBinary("133457799DFF1");
        int[] plaintext = hexStringToBinary("012ABCDEF");

        int[] encrypted = encrypt(plaintext, key);
        System.out.println("Encrypted: " + binaryToHexString(encrypted));

        int[] decrypted = decrypt(encrypted, key);
        System.out.println("Decrypted: " + binaryToHexString(decrypted));
    }

    public static int[] encrypt(int[] plaintext, int[] key) {
        // Initial Permutation
        int[] permuted = permute(plaintext, initialPermutation);

        // Splitting into left and right halves
        int[] left = Arrays.copyOfRange(permuted, 0, 32);
        int[] right = Arrays.copyOfRange(permuted, 32, 64);

        // Generating subkeys
        int[][] subkeys = generateSubkeys(key);

        // 16 rounds of encryption
        for (int round = 0; round < 16; round++) {
            int[] tempRight = right.clone();
            right = xor(left, feistelFunction(right, subkeys[round]));
            left = tempRight;
        }

        // Final permutation
        int[] combined = concatenate(left, right);
        int[] encrypted = permute(combined, inverseInitialPermutation);

        return encrypted;
    }

    public static int[] decrypt(int[] ciphertext, int[] key) {
        // Initial Permutation
        int[] permuted = permute(ciphertext, initialPermutation);

        // Splitting into left and right halves
        int[] left = Arrays.copyOfRange(permuted, 0, 32);
        int[] right = Arrays.copyOfRange(permuted, 32, 64);

        // Generating subkeys
        int[][] subkeys = generateSubkeys(key);

        // 16 rounds of decryption
        for (int round = 15; round >= 0; round--) {
            int[] tempRight = right.clone();
            right = xor(left, feistelFunction(right, subkeys[round]));
            left = tempRight;
        }

        // Final permutation
        int[] combined = concatenate(left, right);
        int[] decrypted = permute(combined, inverseInitialPermutation);

        return decrypted;
    }

    public static int[] feistelFunction(int[] right, int[] subkey) {
        // Expansion Permutation
        int[] expanded = permute(right, eBitSelection);

        // XOR with subkey
        int[] xored = xor(expanded, subkey);

        // Substitution with S-boxes
        int[] substituted = substitute(xored);

        // Permutation
        int[] permuted = permute(substituted, pBox);

        return permuted;
    }

    public static int[] substitute(int[] input) {
        int[] output = new int[32];
        for (int i = 0; i < 8; i++) {
            int[] block = Arrays.copyOfRange(input, i * 6, (i + 1) * 6);
            int row = block[0] * 2 + block[5];
            int col = block[1] * 8 + block[2] * 4 + block[3] * 2 + block[4];
            int value = sBox[i][row][col];
            int[] binaryValue = decimalToBinaryArray(value, 4);
            System.arraycopy(binaryValue, 0, output, i * 4, 4);
        }
        return output;
    }

public static int[] permute(int[] input, int[] permutation) {
    int[] output = new int[permutation.length];
    for (int i = 0; i < permutation.length; i++) {
        output[i] = input[permutation[i] - 1];
    }
    return output;
}


    public static int[] generateSubkey(int[] key, int round) {
        // Left Circular Shift
        int[] shifted = leftCircularShift(key, numberOfShifts[round]);

        // Permuted Choice 2
        return permute(shifted, pc2);
    }

    public static int[][] generateSubkeys(int[] key) {
        int[][] subkeys = new int[16][48];
        // Permuted Choice 1
        int[] permutedKey = permute(key, pc1);

        // Splitting into left and right halves
        int[] left = Arrays.copyOfRange(permutedKey, 0, 28);
        int[] right = Arrays.copyOfRange(permutedKey, 28, 56);

        // Generating subkeys for each round
        for (int round = 0; round < 16; round++) {
            left = leftCircularShift(left, numberOfShifts[round]);
            right = leftCircularShift(right, numberOfShifts[round]);
            int[] combined = concatenate(left, right);
            subkeys[round] = permute(combined, pc2);
        }
        return subkeys;
    }

    public static int[] leftCircularShift(int[] input, int shift) {
        int[] output = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            output[i] = input[(i + shift) % input.length];
        }
        return output;
    }

    public static int[] xor(int[] a, int[] b) {
        int[] result = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            result[i] =            a[i] ^ b[i];
        }
        return result;
    }

    public static int[] concatenate(int[] a, int[] b) {
        int[] result = new int[a.length + b.length];
        System.arraycopy(a, 0, result, 0, a.length);
        System.arraycopy(b, 0, result, a.length, b.length);
        return result;
    }

    public static int[] hexStringToBinary(String hex) {
        int binaryLength = hex.length() * 4;
        int[] binary = new int[binaryLength];
        for (int i = 0; i < hex.length(); i++) {
            int value = Integer.parseInt(hex.substring(i, i + 1), 16);
            int[] bits = decimalToBinaryArray(value, 4);
            System.arraycopy(bits, 0, binary, i * 4, 4);
        }
        return binary;
    }

    public static String binaryToHexString(int[] binary) {
        StringBuilder hex = new StringBuilder();
        for (int i = 0; i < binary.length; i += 4) {
            int value = binaryToDecimal(Arrays.copyOfRange(binary, i, i + 4));
            hex.append(Integer.toHexString(value).toUpperCase());
        }
        return hex.toString();
    }

    public static int[] decimalToBinaryArray(int decimal, int length) {
        int[] binary = new int[length];
        for (int i = length - 1; i >= 0; i--) {
            binary[i] = decimal % 2;
            decimal /= 2;
        }
        return binary;
    }

    public static int binaryToDecimal(int[] binary) {
        int decimal = 0;
        for (int i = 0; i < binary.length; i++) {
            decimal = decimal * 2 + binary[i];
        }
        return decimal;
    }
}

