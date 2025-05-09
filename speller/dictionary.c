// Implements a dictionary's functionality
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 4) ^ tolower(word[i]);
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (!source)
        return false;

    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }

        strcpy(n->word, word);
        unsigned int index = hash(word);
        n->next = table[index];
        table[index] = n;
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            count++;
            cursor = cursor->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    return true;
}
