#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024   // Maximum size for input strings
#define PAD_CHAR '_'   // Padding character

// Function prototypes
void encrypt(const char *plaintext, int key, char *ciphertext);
void decrypt(const char *ciphertext, int key, char *plaintext);

int main(int argc, char *argv[]) {

    char mode = 0; // 'e' for encrypt, 'd' for decrypt
    char *input_file = NULL;
    char *output_file = NULL;
    int key = 0;

    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            mode = 'e';
        } else if (strcmp(argv[i], "-d") == 0) {
            mode = 'd';
        } else if (strcmp(argv[i], "-k") == 0) {
            if (i + 1 < argc) {
                key = atoi(argv[++i]);
                if (key <= 0) {
                    fprintf(stderr, "Invalid key. Key must be a positive integer.\n");
                    return 1;
                }
            } else {
                fprintf(stderr, "Missing key value after -k.\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                output_file = argv[++i];
            } else {
                fprintf(stderr, "Missing output file after -o.\n");
                return 1;
            }
        } else {
            input_file = argv[i];
        }
    }

    if (mode == 0 || input_file == NULL || output_file == NULL || key == 0) {
        fprintf(stderr, "Invalid arguments. Usage: %s -e|-d input.txt -k key -o output.txt\n", argv[0]);
        return 1;
    }

    // Read input file
    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        perror("Error opening input file");
        return 1;
    }

    char input[MAX_LEN];
    if (fgets(input, MAX_LEN, input_fp) == NULL) {
        fprintf(stderr, "Error reading input file.\n");
        fclose(input_fp);
        return 1;
    }
    fclose(input_fp);

    // Remove newline if present
    input[strcspn(input, "\n")] = '\0';

    char output[MAX_LEN];

    // Perform encryption or decryption
    if (mode == 'e') {
        encrypt(input, key, output);
    } else if (mode == 'd') {
        decrypt(input, key, output);
    }

    // Write output to file
    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        return 1;
    }
    fprintf(output_fp, "%s", output);
    fclose(output_fp);

    printf("Operation completed successfully. Output written to %s\n", output_file);
    return 0;
}

// Encryption function using columnar transposition
void encrypt(const char *plaintext, int key, char *ciphertext) {
    int len = strlen(plaintext);
    // Calculate number of rows (rounding up)
    int rows = (len + key - 1) / key;
    int padded_len = rows * key;
    
    // Create a buffer to hold the padded plaintext
    char padded[MAX_LEN];
    strcpy(padded, plaintext);
    // Pad with PAD_CHAR if necessary
    for (int i = len; i < padded_len; i++) {
        padded[i] = PAD_CHAR;
    }
    padded[padded_len] = '\0';

    int index = 0;
    // Read the padded plaintext column by column
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < rows; row++) {
            ciphertext[index++] = padded[row * key + col];
        }
    }
    ciphertext[index] = '\0';
}

// Decryption function (assumes ciphertext was produced by the above encryption)
void decrypt(const char *ciphertext, int key, char *plaintext) {
    int len = strlen(ciphertext);
    
    // Check that ciphertext length is a multiple of key
    if (len % key != 0) {
        fprintf(stderr, "Error: ciphertext length is not divisible by key.\n");
        plaintext[0] = '\0';
        return;
    }
    
    int rows = len / key;
    char matrix[MAX_LEN];
    
    int index = 0;
    // Fill a temporary array with the ciphertext arranged column by column
    // This simulates the original matrix used during encryption.
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < rows; row++) {
            matrix[row * key + col] = ciphertext[index++];
        }
    }
    
    // Read the matrix row by row to recover the plaintext
    index = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < key; col++) {
            plaintext[index++] = matrix[row * key + col];
        }
    }
    plaintext[index] = '\0';
    
    // Optionally, remove any trailing PAD_CHAR characters.
    // (Be cautious: if your original message might end with the pad character, you may not want to remove them.)
    while (index > 0 && plaintext[index - 1] == PAD_CHAR) {
        plaintext[index - 1] = '\0';
        index--;
    }
}
