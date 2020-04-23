// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
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

// Number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int pos = hash(word);
    //printf("hash value %d for word %s\n", pos, w); //debugging purpose
    if(pos != 0)
    {
        //initializing the cursor to point at the first element
        node *cursor = table[pos];
        //iterating over the lenth of the linked list
        while(cursor != NULL)
        {
            //printf("%s ", cursor->word); //debugging purpose
            //strcasecmp returns 0 if the words are same, else returns +ve or -ve value
            if(strcasecmp(cursor->word, word) != 0)
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
    }
    //if word is not found in the hash table return false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    if(strlen(word) == 1)
    {
        char a = tolower(word[0]);
        return ((a - 97) * 676) + 1;
    }
    else if(strlen(word) == 2)
    {
        char a = tolower(word[0]);
        char b = tolower(word[1]);
        if((a > 96) && (a < 123))
        {
            if((b > 96) && (b < 123))
            {
                return ((a - 97) * 676) + (b - 96);
            }
            else
            {
                return ((a - 97) * 676) + 1;
            }
        }
    }
    else
    {
        char a = tolower(word[0]);
        char b = tolower(word[1]);
        char c = tolower(word[2]);
        if((a > 96) && (a < 123))
        {
            if((b > 96) && (b < 123))
            {
                if((c > 96) && (c < 123))
                {
                    return ((a - 97) * 676) + ((b - 97) * 26) + (c - 96);
                }
                else
                {
                    return ((a - 97) * 676) + ((b - 97) * 26) + 1;
                }
            }
            else
            {
                return ((a - 97) * 676) + 1;
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
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
    if(count == 143091)
    {
        return true;
    }
    return false;

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
    //iterating over the length of the hash array
    for(i = 0; i < N; i++)
    {
        //declaring two nodes for the free up process
        //And initializing them to point at the same location as the location in that hash index
        node *temp = table[i];
        node *cursor = table[i];
        //freeing each indivisual nodes after collecting the next node address
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }

    }
    //if all linked lists of the hash table are free, then return true
    if(i == N)
    {
        return true;
    }
    return false;
}

