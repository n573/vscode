#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct tnode
{

    double weight;

    int c;

    struct tnode *left;

    struct tnode *right;

    struct tnode *parent;
};

// GenerateFreqTable
tnode *GenerateFreqTable(char *filename)
{

    FILE *in = fopen(file, 'r');
    tnode *tbl = (tnode *)calloc(128, sizeof(tnode));

    for (int i = 0; i < 128; i++)
    {
        tbl[i].c = i;
        tbl[i].weight = 0;
    }
}

// CreateHuffmanTree
tnode *CreateHuffmanTree()
{
}

// EncodeFile

// DecodeFile

int main(int argc, char *argv[])
{

    // Check the make sure the input parameters are correct

    if (argc != 3)
    {
        printf("Error: The correct format is \"hcompress -e filename\" or \"hcompress -d filename.huf\"\n");
        fflush(stdout);

        exit(1);
    }

    // Create the frequency table by reading the generic file

    struct tnode *leafNodes = createFreqTable("decind.txt");

    // Create the huffman tree from the frequency table

    struct tnode *treeRoot = createHuffmanTree(leafNodes);

    // encode

    if (strcmp(argv[1], "-e") == 0)
    {

        // Pass the leafNodes since it will process bottom up

        encodeFile(argv[2], leafNodes);
    }
    else
    { // decode

        // Pass the tree root since it will process top down

        decodeFile(argv[2], treeRoot);
    }

    return 0;
}