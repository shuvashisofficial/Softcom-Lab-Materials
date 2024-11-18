#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 20
#define MAX_IDENT_LENGTH 20

typedef enum {
  KEYWORD,
  IDENTIFIER
} TokenType;

typedef struct {
  char name[MAX_SYMBOLS][MAX_IDENT_LENGTH];
  char type[MAX_SYMBOLS][MAX_IDENT_LENGTH];
  char dataType[MAX_SYMBOLS][MAX_IDENT_LENGTH];
  char scope[MAX_SYMBOLS][MAX_IDENT_LENGTH];
} SymbolTable;

SymbolTable table;
int symbolCount = 0;

int checkIdentifier(char* token) {
  if (!isalpha(token[0]) && token[0] != '_') return 0;

  int valid = 1;
  int i = 1;
  while (token[i] != '\0') {
    if (!isalpha(token[i]) && !isdigit(token[i]) && token[i] != '_') {
      valid = 0;
      break;
    }
    i++;
  }

  return valid;
}

TokenType getTokenType(char* token, char* keyword) {
  if (strcmp(keyword, token) == 0) {
    return KEYWORD;
  } else if (checkIdentifier(token)) {
    return IDENTIFIER;
  } else {
    return UNKNOWN;
  }
}

void addSymbol(char* name, char* type, char* dataType, char* scope) {
  strcpy(table.name[symbolCount], name);
  strcpy(table.type[symbolCount], type);
  strcpy(table.dataType[symbolCount], dataType);
  strcpy(table.scope[symbolCount], scope);
  symbolCount++;
}

int lookupSymbol(char* name, char* scope) {
  for (int i = 0; i < symbolCount; i++) {
    if (strcmp(table.name[i], name) == 0) {
      if (strcmp(table.type[i], "func") == 0) {
        return i + 1;
      } else if (strcmp(table.scope[i], scope) == 0 ||
          strcmp(scope, "global") == 0 ||
          strcmp(table.scope[i], "global") == 0) {
        return i + 1;
      }
    }
  }

  return 0;
}

void printTable() {
  printf("\nIndex\tName\tType\tData Type\tScope\n");
  for (int i = 0; i < symbolCount; i++) {
    printf("%d\t%s\t%s\t%s\t%s\n",
           i+1, table.name[i], table.type[i],
           table.dataType[i], table.scope[i]);
  }
}
