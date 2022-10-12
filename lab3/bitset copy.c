
// typedef unsigned short bitSet;
typedef unsigned short bitSet;

// bitSet makeBitSet();                  // Create a new bitset
bitSet makeBitSet() // wrong
{
    unsigned short set = 0;
    // bitSet set = "0000000000000000"; // 2 bytes long
    return set;
    // unsigned short bits;
    // bitSet set = bits;
    // return set;
}
void displayBitSet(bitSet bs); // Displays the 16 bits of the bitset to the screen
// void setBit(bitSet *bs, int index);   // Sets bit 'index' of the bitset to 1
void setBit(bitSet *bs, int idx)
{
    // bs[idx] = '1';
    bitSet tmp[sizeof(bs)]; // storage used for the bitwise XOR
    tmp = makeBitSet();
    tmp[idx] = '1';
    // &bs = (bs ^ tmp); // XOR to set
    for (int i = 0; i < idx; i++)
    {
        bs[i] = bs[i] ^ tmp[i];
    }
}
// void clearBit(bitSet *bs, int index); // Sets bit 'index' of the bitset to 0
void clearBit(bitSet *bs, int idx)
{
    bitSet tmp[sizeof(bs)]; // storage used for the bitwise XOR
    tmp[idx] = '0';
    bs = bs & tmp; // AND to clear
}
// int bitValue(bitSet bs, int index);   // Returns the value of the bit at 'index'
int bitValue(bitSet bs, int idx)
{
    return *(&bs + idx); // returns value at given index of the bit set
}
