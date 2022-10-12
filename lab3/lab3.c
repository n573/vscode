#include <stdio.h>
#include "bitset.c"
#include "baseConv.c"
#include <math.h>

/*
 bitSet makeBitSet(); // Create a new bitset
 displayBitSet(bitSet bs); // Displays the 16 bits of the bitset to the screen
void setBit(bitSet *bs, int index); // Sets bit 'index' of the bitset to 1
void clearBit(bitSet *bs, int index); // Sets bit 'index' of the bitset to 0
int bitValue(bitSet bs, int index); // Returns the value of the bit at 'index'
*/

int main()
{
    // bitSet set = makeBitSet();
    // //// bitValue(set,)
    // int *dec = binToDec(&set);

    int num = binToDec("11001");
    printf("%d\t", num);

    // unsigned short bs = makeBitSet();
    bitSet bs = makeBitSet();

    return 0;
}
