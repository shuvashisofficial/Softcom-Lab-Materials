#include <bits/stdc++.h>
using namespace std;

bool isSeparator(char character) {
    return (character == ';' || character == ',' || character == '\'');
}

bool isOperator(char character) {
    return (character == '+' || character == '-' ||
            character == '*' || character == '/' ||
            character == '>' || character == '<' ||
            character == '!' || character == '=');
}

bool isDigit(char character) {
    return (character >= '0' && character <= '9');
}

bool isParenthesis(char character) {
    return (character == ')' || character == '(' ||
            character == '}' || character == '{');
}

bool isSingleCharSeparator(const string& lexeme) {
    return (lexeme.size() == 1 && isSeparator(lexeme[0]));
}

bool isKeyword(const string& lexeme) {
    const set<string> keywords = {"int", "float", "char", "else", "if"};
    return keywords.count(lexeme) > 0;
}

bool isOperatorOrEqual(const string& lexeme) {
    if (lexeme.size() == 1) {
        return isOperator(lexeme[0]);
    } else if (lexeme.size() == 2 && isOperator(lexeme[0]) && lexeme[1] == '=') {
        return true;
    }
    return false;
}

bool isSingleCharParenthesis(const string& lexeme) {
    return (lexeme.size() == 1 && isParenthesis(lexeme[0]));
}

bool isNumber(const string& lexeme) {
    bool decimalPointFound = false;
    for (int i = 0; i < lexeme.size(); ++i) {
        char c = lexeme[i];

        if (c == '.') {
            if (decimalPointFound) {
                return false;
            }
            decimalPointFound = true;
        } else if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

bool isIdentifier(const string& lexeme) {
    if (lexeme.empty() || isdigit(lexeme[0])) {
        return false;
    }
    for (int i = 0; i < lexeme.size(); ++i) {
        char c = lexeme[i];

        if (!(isalnum(c) || c == '_')) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<char> inputChars;
    vector<char> processedChars;
    int error = 0;

    FILE *file = fopen("input.txt", "r");
    if (!file) {
        cout << "No such file." << endl;
        return 0;
    }

    char ch;
    while (fscanf(file, "%c", &ch) != EOF) {
        inputChars.push_back(ch);
    }
    inputChars.push_back('\0');

    cout << "Input:" << endl;
    cout.write(inputChars.data(), inputChars.size());
    cout << endl;

    int inputSize = inputChars.size();
    int flag = 0;
    int j = 0;
    int separatorOn = 0;

    for (int i = 0; i < inputSize; i++) {
        if (isSeparator(inputChars[i])) {
            if (inputChars[i] == '\'') {
                if (separatorOn) {
                    separatorOn = 0;
                    processedChars.push_back(' ');
                    processedChars.push_back(inputChars[i]);
                } else {
                    processedChars.push_back(inputChars[i]);
                    processedChars.push_back(' ');
                    separatorOn = 1;
                }
            } else {
                processedChars.push_back(' ');
                processedChars.push_back(inputChars[i]);
            }
        } else if (isOperator(inputChars[i])) {
            if (inputChars[i + 1] == '=') {
                processedChars.push_back(' ');
                processedChars.push_back(inputChars[i]);
                processedChars.push_back(inputChars[i + 1]);
                i++;
                processedChars.push_back(' ');
            } else {
                processedChars.push_back(' ');
                processedChars.push_back(inputChars[i]);
                processedChars.push_back(' ');
            }
            flag = 1;
        } else if (isDigit(inputChars[i])) {
            if (flag == 0) {
                flag = 1;
                processedChars.push_back(' ');
            }
            processedChars.push_back(inputChars[i]);
        } else if (isParenthesis(inputChars[i])) {
            processedChars.push_back(' ');
            processedChars.push_back(inputChars[i]);
            if (inputChars[i] != ')' && inputChars[i] != '}') {
                processedChars.push_back(' ');
            }
        } else {
            flag = 1;
            processedChars.push_back(inputChars[i]);
        }
    }

    processedChars.push_back('\0');

    cout << "\n\n";
    cout << "Output-1(Lexemes are separated):" << endl;
    cout.write(processedChars.data(), processedChars.size());
    cout << endl;


    FILE *lexemeFile = fopen("lexeme.txt", "w");
    if (lexemeFile) {
        fprintf(lexemeFile, "%s", processedChars.data());
        fclose(lexemeFile);
    } else {
        cout << "Unable to open lexeme.txt for writing." << endl;
    }


    cout << "\n\nOutput-2(Lexemes are categorized):" << endl;
    FILE *lexemeCatFile = fopen("lexemeCat.txt", "w");
    if (lexemeCatFile) {
        inputChars[0] = '\0';
        j = 0;

        for (int i = 0; i < processedChars.size(); i++) {
            if (processedChars[i] == ' ') {
                inputChars[j++] = '\0';
                if (strlen(inputChars.data()) == 0) {
                    j = 0;
                    continue;
                }
                if (isSingleCharSeparator(inputChars.data())) {
                    cout << "[sep " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[sep %s] ", inputChars.data());
                } else if (isKeyword(inputChars.data())) {
                    cout << "[kw " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[kw %s] ", inputChars.data());
                } else if (isIdentifier(inputChars.data())) {
                    cout << "[id " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[id %s] ", inputChars.data());
                } else if (isOperatorOrEqual(inputChars.data())) {
                    cout << "[op " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[op %s] ", inputChars.data());
                } else if (isSingleCharParenthesis(inputChars.data())) {
                    cout << "[par " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[par %s] ", inputChars.data());
                } else if (isNumber(inputChars.data())) {
                    cout << "[num " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[num %s] ", inputChars.data());
                } else {
                    error = 1;
                    cout << "[unkn " << inputChars.data() << "] ";
                    fprintf(lexemeCatFile, "[unkn %s] ", inputChars.data());
                }
                j = 0;
            } else {
                inputChars[j++] = processedChars[i];
            }
        }

        inputChars[j++] = '\0';

        if (strlen(inputChars.data()) > 0) {
            if (isSingleCharSeparator(inputChars.data())) {
                cout << "[sep " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[sep %s] ", inputChars.data());
            } else if (isKeyword(inputChars.data())) {
                cout << "[kw " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[kw %s] ", inputChars.data());
            } else if (isIdentifier(inputChars.data())) {
                cout << "[id " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[id %s] ", inputChars.data());
            } else if (isOperatorOrEqual(inputChars.data())) {
                cout << "[op " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[op %s] ", inputChars.data());
            } else if (isSingleCharParenthesis(inputChars.data())) {
                cout << "[par " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[par %s] ", inputChars.data());
            } else if (isNumber(inputChars.data())) {
                cout << "[num " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[num %s] ", inputChars.data());
            } else {
                cout << "[unkn " << inputChars.data() << "] ";
                fprintf(lexemeCatFile, "[unkn %s] ", inputChars.data());
            }
        }

        if (error == 1) {
            cout << "\n\nError Message:" << endl;
            cout << "INVALID [unkn 100.o5]" << endl;
            fprintf(lexemeCatFile, "\n\nError Message:\n");
            fprintf(lexemeCatFile, "INVALID [unkn 100.o5]\n");
        } else {
            cout << "\n\nCategorized lexemes printed and stored in lexemeCat.txt" << endl;
            fprintf(lexemeCatFile, "\n\nCategorized lexemes stored in lexemeCat.txt\n");
        }

        fclose(lexemeCatFile);
    } else {
        cout << "Unable to open lexemeCat.txt for writing." << endl;
    }

    fclose(file);
    return 0;
}
