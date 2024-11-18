
#include <stdio.h>

void encryptMonoalphabetic(char text[], char key[]) {
    for (int i = 0; text[i]; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = key[text[i] - 'A'] + ('A' - 'a');
            } else {
                text[i] = key[text[i] - 'a'];
            }
        }
    }
}

void decryptMonoalphabetic(char text[], char key[]) {
    for (int i = 0; text[i]; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            for (int j = 0; j < 26; j++) {
                if (text[i] == key[j]) {
                    if (text[i] >= 'a' && text[i] <= 'z') {
                        text[i] = 'a' + j;
                    } else {
                        text[i] = 'A' + j;
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    char text[100], key[26];

    printf("Enter the text: ");
    scanf("%99[^\n]", text); // Read up to 99 characters until newline

    printf("Enter the key (26 unique letters): ");
    scanf("%25s", key); // Read up to 25 characters, no whitespace allowed

    if (strlen(key) != 26) {
        printf("Invalid key length. Please enter a key with 26 unique letters.\n");
        return 1;
    }

    encryptMonoalphabetic(text, key);
    printf("Encrypted Text: %s\n", text);

    decryptMonoalphabetic(text, key);
    printf("Decrypted Text: %s\n", text);

    return 0;
}
