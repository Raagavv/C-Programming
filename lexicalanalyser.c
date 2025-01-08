#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is a keyword
int isKeyword(const char *word) {
    const char *keywords[] = {"int", "float", "if", "else", "while", "return", "void", "char"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    char operators[] = {'+', '-', '*', '/', '=', '<', '>', '!', '%'};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < numOperators; i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to analyze a file for lexical elements
void lexicalAnalyzer(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", fileName);
        return;
    }

    char ch, buffer[100];
    int bufferIndex = 0;

    printf("Lexical Analysis:\n");

    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch)) {
            buffer[bufferIndex++] = ch;
        } else {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                if (isKeyword(buffer)) {
                    printf("Keyword: %s\n", buffer);
                } else {
                    printf("Identifier: %s\n", buffer);
                }
                bufferIndex = 0;
            }
            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            } else if (!isspace(ch)) {
                printf("Other: %c\n", ch);
            }
        }
    }

    if (bufferIndex > 0) {
        buffer[bufferIndex] = '\0';
        if (isKeyword(buffer)) {
            printf("Keyword: %s\n", buffer);
        } else {
            printf("Identifier: %s\n", buffer);
        }
    }

    fclose(file);
}

int main() {
    char fileName[100];

    printf("Enter the name of the input file: ");
    scanf("%s", fileName);

    lexicalAnalyzer(fileName);

    return 0;
}
