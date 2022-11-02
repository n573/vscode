//#include "hcompress.h"
#include <stdio.h>
#include <stdlib.h>

// structures
typedef node
{ // linkedlist node
    struct node *next;
    struct node *prev;
    struct tnode *value; // accessing the tnode struct in ll
}
linkedList;

typedef struct tnode
{
    int weight;
    int c;

    struct tnode *left;
    struct tnode *right;
    struct tnode *parent;

} tnode;

// prototypes
linkedList *llCreate();
int llisEmpty(linkedList *ll);
void llDisplay(linkedList *ll);
void llAdd(linkedList **ll, linkedList *newValue);
void list_add_in_order(linkedList **ll, linkedList *newValue);
void llFree(linkedList **ll);
linkedList *llRemove(linkedList **ll, linkedList *input);
