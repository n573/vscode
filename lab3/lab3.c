#include <stdio.h>
#include "bitset.c"
#include "baseConv.c"
#include <math.h>

/*
 * Nathan Cauwet
 */

/*
    REQUIRED FUNCs in workspace
 bitSet makeBitSet(); // Create a new bitset
 displayBitSet(bitSet bs); // Displays the 16 bits of the bitset to the screen
void setBit(bitSet *bs, int index); // Sets bit 'index' of the bitset to 1
void clearBit(bitSet *bs, int index); // Sets bit 'index' of the bitset to 0
int bitValue(bitSet bs, int index); // Returns the value of the bit at 'index'
*/

int main()
{
    // test number (decimal 25)
    int num = binToDec("11001");
    printf("%d\t", num);

    // unsigned short bs = makeBitSet();
    // bitSet bs = makeBitSet();

    // setBit(&bs, 1);

    // displayBitSet(bs);

    // printf("dec2bin for 25: %s", decToBin(25));
    // printf("bin2dec for 11001: %d", binToDec("11001"));

    return 0;
}
