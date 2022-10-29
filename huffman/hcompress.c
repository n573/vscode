#include <stdio.h>
#include <stdlib.h>
#include "hcompress.h"

// struct tnode
// {

//     double weight;

//     int c;

//     struct tnode *left;

//     struct tnode *right;

//     struct tnode *parent;
// };

// GenerateFreqTable
tnode *createFreqTable(char *filename)
{

    FILE *in = fopen(filename, "r");
    tnode *tbl = (tnode *)calloc(128, sizeof(tnode));

    for (int i = 0; i < 128; i++)
    {
        tbl[i].c = i;
        tbl[i].weight = 0;
    }

    int buffer = fgetc(in);
    if (buffer == EOF)
    {
        printf("File not found\n");
        exit(1);
    }

    while (buffer != EOF)
    { // run until  end of file
        bVal(&tbl, buffer);
        buffer = fgetc(in); // holds bump table
    }

    fclose(in);

    return tbl;
}
/*
// CreateHuffmanTree
tnode *CreateHuffmanTree(struct tnode *tree)
{
}

// EncodeFile
void EncodeFile(char *input, tnode *branch)
{
}

// DecodeFile
void DecodeFile(char *input, tnode *root)
{
}
*/
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
    /*
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
    */
    return 0;
}