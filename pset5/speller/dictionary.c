// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<strings.h>
#include<ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//count number of words
int count = 0;

//for hash function
const int p = 31;

// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char lw[len + 1];
    for(int i = 0; i < len; i++)
    {
        lw[i] = tolower(word[i]);
    }
    lw[len] = '\0';

    int pos = hash(lw);
    //initializing the cursor to point at the first element
    node *cursor = table[pos];
    //iterating over the lenth of the linked list
    while(cursor != NULL)
    {
        //strcmp returns 0 if the words are same, else returns +ve or -ve value
        if(strcmp(cursor->word, lw) != 0)
        {
            //if the word is not same go to the next one
            cursor = cursor->next;

        }
        else
        {
            //if match found then return true
            return true;
        }
    }
    //if word is not found in the hash table return false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int h = 0;
    int powr = 1;
    while((*word) != '\0')
    {
        h = (h + ((*word) - 'a' + 1) * powr) % N;
        powr = (powr * p) % N;
        word++;
    }
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file;
    //open the dictionary file
    file = fopen(dictionary, "r");
    //return false if NULL
    if(file == NULL)
    {
        return false;
    }
    //declare a temporary string of size longest possible word in english language + 1
    char word[46];
    //get the each word from the dictonary to the temp word variable and continue throughout the file
    while(fscanf(file, "%s", word) != EOF)
    {
        //allocate temporary node pointer and do the initial safety check
        node *w = malloc(sizeof(node));
        if(w == NULL)
        {
            return false;
        }
        //copy the word to the temporary node variable
        strcpy(w->word, word);
        //counting number of words for the "size" function
        count += 1;
        //now assigning the next block of the tmp node to the corrosponding hash index
        w->next = table[hash(word)];
        //now linking the temp node to the hash table of that index
        table[hash(word)] = w;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    int i;
    FILE *fp;
    fp = fopen("sample.txt", "w");
    //iterating over the length of the hash array
    for(i = 0; i < N; i++)
    {
        //declaring two nodes for the free up process
        node *cursor = table[i];
        //freeing each indivisual nodes after collecting the next node address
        //fprintf(fp, "%d  :", i+1);
        while(cursor != NULL)
        {
            node *temp = cursor;
            //fprintf(fp, "%s  ", cursor->word);
            cursor = cursor->next;
            free(temp);
        }
        //fprintf(fp, "\n\n");
    }
    fclose(fp);
    return true;
}