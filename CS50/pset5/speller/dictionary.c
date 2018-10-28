// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table with N number of buckets, in this case N = 26
//a hash table is an array of linked lists. Each element of array is a node * pointer
//declare an array, type node *pointer, name hash_table, size 26. Because of the struct node above, this array already
//contains 26 node *pointers, index 0-25, we are going to use each of these pointer as the head
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false. For each word in the dictionary text file,
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    //fscanf take a file, scan for a string an put it into a variable word, does this until it reaches end of file
    //what goes inside the loop? insert each word into a node in the dictionary.
    while (fscanf(file, "%s", word) != EOF)
    {
        //for every new word scan, we malloc some memory for it, new_node is a pointer
        node *new_node = malloc(sizeof(node));
        //check if malloc succeed, when you run out of memory, malloc will return NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        //assign the scanned word into the memory of the node just created
        strcpy(new_node->word, word);

        //next, how do we know which word will go into which linked lists? we're going to have 26 (0-25) linked lists, which is the size of our hash table.
        //use the hash function, which takes a string, returns an index < number of buckets (26), we'll put the node into
        //whichever linked list with this index

        //insert that node into the head of the linked list, very important to maintain all links in the linked list
        //there is a "head" pointer that you keep in memory, that points to the first actual node (a node has 2 parts,
        //the word + a pointer that points to the next node). Make sure your new_node's pointer point to the first node first,
        //before pointing that "head" pointer to the new_node or you risk losing the whole list
        //need the memory add of the head pointer, copy that address to the current node
        //ex: if pc is the pointer, then *pc is the data that pc points to, * is the dereference operator
        //we don't want the data, we just want to the memory address
        new_node->next = hashtable[hash(new_node->word)];


        //once the current node has the address of the first actual node, then we can point the head to the current node by
        //copying the address in new_node
        //& means get the address, int m; pk = &m, means pointer pk gets the address of m, aka, pk points to m
        hashtable[hash(new_node->word)] = new_node;

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            counter++;
            cursor = cursor->next;
        }
    }

    return counter;

}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //if the word exists, it can be found the hash table
    //which bucket would the word be in?
    //creat a cursor pointer, no malloc, we just need a pointer to traverse the linked list
    node *cursor = hashtable[hash(word)];
    while (cursor != NULL)
    {
        //compare the given word and the word on that node, if they match, that word exists

        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }

    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
