#include <stdio.h>
#include <math.h>

typedef unsigned short bitSet;

// make bitset (short = 16 bytes)
bitSet makeBitSet()
{
    bitSet bitset = 16;
    return bitset;
}

// Functions
void displayBitSet(bitSet bs);
void setBit(bitSet *bs, int index);
void clearBit(bitSet *bs, int index);
int bitValue(bitSet bs, int index);

// Test
// int main()
// {
//     // bitset make
//     bitSet bitset = makeBitSet();
//     // bitset display
//     displayBitSet(bitset);
//     // set bit
//     printf("\nDisplay bitset after setting the 2nd index value\n");
//     setBit(&bitset, 2);
//     displayBitSet(bitset);
//     // clear bit
//     printf("\nDisplay bitset after clearing the 2nd index value\n");
//     clearBit(&bitset, 2);
//     displayBitSet(bitset);
//     // index 12
//     printf("\nDisplay index value at 12 = %d\n", bitValue(bitset, 12));
//     return 0;
// }

// Displays the bitset
void displayBitSet(bitSet bs)
{
    int idx;
    for (idx = 0; idx < 16; idx++)
    {
        printf("%d", ((bs & (int)pow(2, (15 - idx))) >> (15 - idx)));
    }
}

// Sets bit at idx of the set to 1
void setBit(bitSet *bs, int idx)
{
    *bs = *bs | (int)pow(2, idx); // bitwise 'OR' is used to set the bit
}

// Sets bit idx of the bitset to 0
void clearBit(bitSet *bs, int idx)
{
    *bs = *bs & (255 - (int)pow(2, idx)); // bitwise AND is used to clear the bit
}

// Returns the value of the bit at idx
int bitValue(bitSet bs, int idx)
{
    return ((bs & (int)pow(2, idx)) >> idx);
}
