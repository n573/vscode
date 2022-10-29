#include <stdio.h>
#include <string.h>

typedef struct hcode
{
    char *code;
    char character;
    int length;

} hcode;

typedef struct tnode
{
    int weight;
    int c;

    struct tnode *left;
    struct tnode *right;
    struct tnode *parent;

} tnode;

// interface (or whatever it's called in C, 'interface' is technically the term for it in java)

tnode *createFreqTable(char *file);

tnode *CreateHuffmanTree(struct tnode *tree);

void EncodeFile(char *input, tnode *branch);

void DecodeFile(char *input, tnode *root);

int tnodeEq(tnode one, tnode two);

void bumpValue(tnode **table, int ch);

hcode getHuffCode(tnode *leaf);