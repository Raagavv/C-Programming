#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a file using Run-Length Encoding (RLE)
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error: Could not open file.\n");
        return;
    }

    char ch, prev = 0;
    int count = 0;

    while ((ch = fgetc(in)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            if (count > 0) {
                fprintf(out, "%c%d", prev, count);
            }
            prev = ch;
            count = 1;
        }
    }

    if (count > 0) {
        fprintf(out, "%c%d", prev, count);
    }

    fclose(in);
    fclose(out);
    printf("File compressed successfully.\n");
}

// Function to decompress a file compressed with RLE
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error: Could not open file.\n");
        return;
    }

    char ch;
    int count;

    while (fscanf(in, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("File decompressed successfully.\n");
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Run-Length Encoding Tool\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter input file name: ");
        scanf("%s", inputFile);
        printf("Enter output file name: ");
        scanf("%s", outputFile);
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        printf("Enter input file name: ");
        scanf("%s", inputFile);
        printf("Enter output file name: ");
        scanf("%s", outputFile);
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}