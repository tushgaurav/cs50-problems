// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 70;

// Tracking the number of words
int num = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char lword[strlen(word)];
    strcpy(lword, word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        lword[i] = tolower(lword[i]);
    }

    int hashed = hash(lword);
    node *list = table[hashed];
    while (list != NULL)
    {
        if (strcasecmp(word, list->word) == 0)
        {
            return true;
        }
        list = list->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // EasyHash Algorithm v0.1 Alpha (refer hash.c)
    int temp = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        temp = temp + word[i];
    }
    int digest = temp % N;

    return digest;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    node *location = NULL;
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    int x = 0;

    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }

        strcpy(n->word, word);
        num++;
        x = hash(n->word);

        location = table[x];

        n->next = table[x];
        table[x] = n;

    }
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return num;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        while (head != NULL)
        {
            node *tmp = head;
            head = head->next;
            free(tmp);
        }

        if (head == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
