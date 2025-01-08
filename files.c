#include <stdio.h>
#include <stdlib.h>

// Function to create a new file
void createFile(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error: Could not create file '%s'.\n", fileName);
        return;
    }
    fclose(file);
    printf("File '%s' created successfully.\n", fileName);
}

// Function to write content to a file
void writeFile(const char *fileName, const char *content) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", fileName);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content written to '%s'.\n", fileName);
}

// Function to append content to a file
void appendFile(const char *fileName, const char *content) {
    FILE *file = fopen(fileName, "a");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for appending.\n", fileName);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
    printf("Content appended to '%s'.\n", fileName);
}

// Function to read and display content of a file
void readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: File '%s' does not exist or could not be opened.\n", fileName);
        return;
    }

    char ch;
    printf("Content of '%s':\n", fileName);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\n");
}

int main() {
    const char *fileName = "example.txt";

    // Create a new file
    createFile(fileName);

    // Write content to the file
    writeFile(fileName, "Hello, this is the first line.\n");

    // Append more content to the file
    appendFile(fileName, "This is an appended line.\n");

    // Read and display the content of the file
    readFile(fileName);

    return 0;
}
