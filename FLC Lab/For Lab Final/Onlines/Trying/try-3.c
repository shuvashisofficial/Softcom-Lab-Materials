#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function declarations
void A();
void X();

char str[1000];
int i, l;
bool f;

void A() {
    if (str[i] == 'a') {
        i++;
        X();
        if (str[i] == 'd') {
            i++;
            f = 1;
        } else {
            f = 0;
        }
    } else {
        f = 0;
    }
}

void X() {
    if (str[i] == 'b' && str[i + 1] == 'b') {
        i += 2;
        X();
    } else if (str[i] == 'b' && str[i + 1] == 'c') {
        i += 2;
        X();
    } else {
        // epsilon case
    }
}

int main() {
    printf("Enter a string to check: ");
    scanf("%s", str);

    i = 0;
    l = strlen(str);
    f = 0;

    A();

    if (f && i == l) {
        printf("The input string follows the grammar.\n");
    } else {
        printf("The input string does not follow the grammar.\n");
    }

    return 0;
}

