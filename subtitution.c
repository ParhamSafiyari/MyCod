#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
bool isValid(string key);
void replace_key(string key, char mappingLower[], char mappingUpper[]);
string encrypt_message(string message, char mappingLower[], char mappingUpper[]);

int main(int argc, string argv[])
{
    // Check if exactly one command-line argument is provided.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Store the key from the command-line argument.
    string key = argv[1];

    // Validate the key.
    if (!isValid(key))
    {
        return 1;
    }

    // Create mapping arrays for the substitution cipher (27 elements to include the null terminator).
    char mappingLower[27];
    char mappingUpper[27];
    replace_key(key, mappingLower, mappingUpper);

    // Prompt the user for plaintext.
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the mapping arrays.
    string ciphertext = encrypt_message(plaintext, mappingLower, mappingUpper);

    // Print the ciphertext without an extra newline, then print a newline after.
    printf("ciphertext: %s\n", ciphertext);

    // Free the dynamically allocated memory for ciphertext.
    free(ciphertext);

    // Return 0 to indicate successful termination.
    return 0;
}

// isValid checks if the key meets these conditions:
// 1. The key must have exactly 26 characters.
// 2. The key must include only alphabetic characters.
// 3. The key must not contain any repeated characters (duplicates).
bool isValid(string key)
{
    int len = strlen(key);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Create a frequency array for each letter.
    int freq[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return false;
        }
        int index = tolower(key[i]) - 'a';
        freq[index]++;
        if (freq[index] > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
    }
    return true;
}

// replace_key creates two mapping arrays for the substitution cipher:
// mappingLower holds the lowercase mapping,
// mappingUpper holds the uppercase mapping.
void replace_key(string key, char mappingLower[], char mappingUpper[])
{
    for (int i = 0; i < 26; i++)
    {
        mappingLower[i] = tolower(key[i]);
        mappingUpper[i] = toupper(key[i]);
    }
    mappingLower[26] = '\0';
    mappingUpper[26] = '\0';
}

// encrypt_message encrypts the plaintext using the substitution cipher.
// For each alphabetic character in the plaintext:
// - Its position in the alphabet is determined,
// - Then it is replaced with the corresponding character from the key mapping.
// Non-alphabetic characters remain unchanged, preserving their original case.
string encrypt_message(string message, char mappingLower[], char mappingUpper[])
{
    int length = strlen(message);

    // Allocate memory for the ciphertext (length + 1 for the null terminator).
    char *ciphertext = malloc(length + 1);
    if (ciphertext == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < length; i++)
    {
        if (isalpha(message[i]))
        {
            if (islower(message[i]))
            {
                int index = message[i] - 'a';
                ciphertext[i] = mappingLower[index];
            }
            else  // Uppercase letter
            {
                int index = message[i] - 'A';
                ciphertext[i] = mappingUpper[index];
            }
        }
        else
        {
            // Non-alphabetic characters remain unchanged.
            ciphertext[i] = message[i];
        }
    }
    ciphertext[length] = '\0';
    return ciphertext;
}
