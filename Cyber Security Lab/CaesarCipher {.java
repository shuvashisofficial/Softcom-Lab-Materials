public class CaesarCipher {

    // Encrypts text using a shift specified by the key
    public static String encrypt(String plaintext, int key) {
        StringBuilder ciphertext = new StringBuilder();

        for (int i = 0; i < plaintext.length(); i++) {
            char ch = plaintext.charAt(i);

            // Encrypt uppercase letters
            if (Character.isUpperCase(ch)) {
                char encryptedChar = (char) ((ch + key - 'A') % 26 + 'A');
                ciphertext.append(encryptedChar);
            }
            // Encrypt lowercase letters
            else if (Character.isLowerCase(ch)) {
                char encryptedChar = (char) ((ch + key - 'a') % 26 + 'a');
                ciphertext.append(encryptedChar);
            }
            // Keep non-alphabetic characters unchanged
            else {
                ciphertext.append(ch);
            }
        }

        return ciphertext.toString();
    }

    public static void main(String[] args) {
        String plaintext = "Hello, World!";
        int key = 3;

        // Encrypt the plaintext
        String ciphertext = encrypt(plaintext, key);

        // Display the results
        System.out.println("Original: " + plaintext);
        System.out.println("Encrypted: " + ciphertext);
    }
}
