// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"



// TODO: Choose number of buckets in hash table
const unsigned int N = 27 * 27;

// Hash table
node *table[N];
int num = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *p = table[hash(word)];
    while (p)
    {
        if (strcasecmp(p->word, word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int ret = 0;
    if (word[1] == '\'')
    {
        ret = (tolower(word[0]) - 'a') + 26 * 26;
    }
    else if (word[1])
    {
        ret = (tolower(word[0]) - 'a') + 26 * (tolower(word[1]) - 'a');
    }
    else
    {
        ret = (tolower(word[0]) - 'a');
    }
    return ret;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Initialize table array
    for (int i = 0; i < N; i++)
    {
       table[i] = NULL;
    }
    // Open file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    // Read in word and create linked list
    char word[LENGTH + 1] = {'\0'};
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *p = calloc(sizeof(node), 1);
        if (table[hash(word)])
        {
            p->next = table[hash(word)]->next;
            table[hash(word)]->next = p;
        }
        else
        {
            table[hash(word)] = p;
        }
        strcpy(p->word, word);
        num++;
    }
    // Close the file
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return num;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        freep(table[i]);
    }
    return true;
}

void freep(node *p)
{
    while (p != NULL)
    {
        node *new = p;
        p = p->next;
        free(new);
        new = NULL;
    }
}
