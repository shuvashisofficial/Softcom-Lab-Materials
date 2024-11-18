#include <stdio.h>
#include <string.h>

#include <stdio.h>

int checkAssignmentError(char inp[], int inpi, int lineNum) {
    int i = 0;
    int assignmentError = 0;
    int inParentheses = 0;

    while (i < inpi - 1) {
        if (inp[i] == '(') {
            inParentheses = 1;
        } else if (inp[i] == ')') {
            inParentheses = 0;
        } else if (inp[i] == '=' && inp[i + 1] == '=' && !inParentheses) {
            printf("!!!!!Error Detected!!!!! Line %d: %s", lineNum, inp);
            printf("Assignment error: '==' used instead of '='\n");
            assignmentError = 1;
        }
        i++;
    }

    return assignmentError;
}

int main() {
    char line[256]; // Example line
    int lineNum = 1; // Example line number
    FILE *file = fopen("comment.txt", "r");
        while (fgets(line, sizeof(line), file)) {
        printf("Line %d: %s", lineNum, line);
        int assignmentError = checkAssignmentError(line, sizeof(line) - 1, lineNum);
        lineNum++;
    }

    fclose(file);


    return 0;
}
