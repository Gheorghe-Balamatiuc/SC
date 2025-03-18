#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    char *input_file = NULL;
    char *output_file = NULL;
    int key = 0;

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            input_file = argv[++i];
            key = 1;
        } else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            input_file = argv[++i];
            key = -1;
        } else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
            key = key * atoi(argv[++i]);
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        }
    }

    if (!input_file || !output_file || key == 0) {
        printf("Invalid arguments. Usage: %s -e <input_file> -k <key> -o <output_file>\n", argv[0]);
        return 1;
    }

    // Reduce the key to a valid range
    key = key % 26; // For letters (26 characters in the alphabet)
    if (key < 0) {
        key += 26; // Ensure the key is positive
    }

    // Open input and output files
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input || !output) {
        printf("Error opening files.\n");
        return 1;
    }

    char text[500], ch;

    while(!feof(input)) {
        fscanf(input, "%s", text);

        // Encrypt the text
        for (int i = 0; text[i] != '\0'; ++i) {
            ch = text[i];
            if (isalpha(ch)) {
                if (islower(ch)) {
                    ch = (ch - 'a' + key) % 26 + 'a';
                }
                if (isupper(ch)) {
                    ch = (ch - 'A' + key) % 26 + 'A';
                }
            }
            text[i] = ch;
        }

        fprintf(output, "%s", text);
        if (!feof(input)) {
            fprintf(output, " ");
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}