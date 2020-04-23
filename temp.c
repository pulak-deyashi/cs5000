// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//count number of words
int count = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int pos = hash(word);
    if(pos != 0)
    {
        for(node *tmp = table[pos-1]; tmp != NULL; tmp = tmp->next)
        {
            if()
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    if((word[0] > 96) && (word[0] < 123)) return (word[0] - 96);
    else if((word[0] > 64) && (word[0] < 91)) return (word[0] - 64);
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file;
    file = fopen(dictionary, "r");
    if(file == NULL) return false;
    char word[46];
    while(fscanf(file, "%s", word) != EOF)
    {
        node *w = malloc(sizeof(node));
        if(w == NULL) return false;
        strcpy(w->word, word);
        count += 1;
        w->next = table[hash(word)];
        table[hash(word)] = w;
    }
    if(fscanf(file, "%s", word) != EOF) return true;
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(load(dictionary))
    return count;
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
