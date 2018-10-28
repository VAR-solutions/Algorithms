#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Alphabet in min plus space
#define ALPHABET_SIZE 27

// trie node
typedef struct TrieNode TrieNode;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    // maxLength represents the size of largest path in trie
    int maxLength;
    // isEndOfWord is true if the node represents end of a word
    bool isEndOfWord;
    // weight exists if the node represents end of a word
    int weight;
    // maxWeight is the maximum weight of node recursive children
    int maxWeight;
    // bestChild is the child who has the path for the biggest weight
    int bestChild;
};

TrieNode *getNode();
void insert(struct TrieNode *root, const char *key, int length, int weight);
void searchMaximum(FILE* file, struct TrieNode *node, const char *key, int length);
void getMaxTrie(FILE* file, struct TrieNode *node, int position);
void printTrie(FILE* file, struct TrieNode *root);
void destroy(struct TrieNode *root);