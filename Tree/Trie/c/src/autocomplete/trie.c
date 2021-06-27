#include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int minValue(int a, int b)
{
    return ((a) < (b)) ? (a) : (b);
}

int maxValue(int a, int b)
{
    return ((a) >= (b)) ? (a) : (b);
}

int charToIndex(char c)
{
    if (c == ' ')
    {
        return 26;
    }
    else
    {
        return ((int)c - (int)'a');
    }
}

char indexToChar(int c)
{
    if (c == 26)
    {
        return ' ';
    }
    else
    {
        return ('a' + c);
    }
}

TrieNode *getNode()
{
    struct TrieNode *node = NULL;
    node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (node)
    {
        int i;
        for (i = 0; i < ALPHABET_SIZE; i++)
            node->children[i] = NULL;
        node->isEndOfWord = false;
        node->weight = 0;
        node->maxWeight = 0;
        node->maxLength = 0;
        node->bestChild = 0;
    }
    return node;
}

void insert(struct TrieNode *root, const char *key, int length, int weight)
{
    int charIndex;
    struct TrieNode *floor = root;
    for (int i = 0; i < length; i++)
    {
        // update reference of maxWeight of children and bestChild of root
        if (floor->maxWeight < weight)
        {
            floor->maxWeight = weight;
            floor->bestChild = charToIndex(key[i]);
        }
        // update reference of maxLength
        if (length > floor->maxLength)
        {
            floor->maxLength = length;
        }
        // create or find the children
        charIndex = charToIndex(key[i]);
        if (!floor->children[charIndex])
            floor->children[charIndex] = getNode();
        floor = floor->children[charIndex];
    }
    // mark last node as end and put weight
    floor->isEndOfWord = true;
    floor->weight = weight;
}

void printRestQuery(FILE* file, const char *key, int length, int position)
{
    for (int i = position; i < length; i++)
    {
        fprintf(file, "%c", key[i]);
    }
}

void getMaxTrie(FILE* file, struct TrieNode *node, int position)
{
    struct TrieNode *floor = node;
    int length = (floor->maxLength);
    for (int i = position; i < length; i++)
    {
        if (!floor->children[floor->bestChild])
        {
            return;
        }
        if(floor->isEndOfWord && floor->weight >= floor->maxWeight){
            // The best
            return;
        }
        fprintf(file, "%c", indexToChar(floor->bestChild));
        floor = floor->children[floor->bestChild];
    }
}

void searchMaximum(FILE* file, struct TrieNode *node, const char *key, int length)
{
    int charIndex;
    struct TrieNode *floor = node;
    for (int i = 0; i < length; i++)
    {
        charIndex = charToIndex(key[i]);
        if (floor->children[charIndex])
        {
            // If exists, print char
            floor = floor->children[charIndex];
            fprintf(file, "%c", indexToChar(charIndex));
        }
        else
        {
            // Query doesn't exists, print rest
            printRestQuery(file, key, length, i);
            return;
        }
    }
    if (floor->isEndOfWord)
    {
        // Query is in trie
        return;
    }
    else
    {
        // Query is not in trie, keep looking
        getMaxTrie(file, floor, length);
    }
}

void destroy(struct TrieNode *node)
{
    struct TrieNode *floor = node;
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(floor->children[i])
            destroy(floor->children[i]);
    }
    free(floor);
}