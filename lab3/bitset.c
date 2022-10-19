
// typedef unsigned short bitSet;
typedef unsigned short bitSet; // short is 16 bits

// bitSet makeBitSet();                  // Create a new bitset
bitSet makeBitSet() // wrong
{
    unsigned short set = 0;
    // unsigned short set;
    // bitSet set = "0000000000000000"; // 2 bytes long
    return set;
}

// displayBitSet(bitSet bs); // Displays the 16 bits of the bitset to the screen
void displayBitSet(bitSet bs)
{
    for (int i = 0; i < __SIZEOF_SHORT__; i++)
    {
        printf("bitSet = %hn", &bs);
    }
}

//  void setBit(bitSet *bs, int index);   // Sets bit 'index' of the bitset to 1
void setBit(bitSet *bs, int idx)
{
    // bs[idx] = '1';
    // bitSet tmp[sizeof(bs)]; // storage used for the bitwise XOR
    bitSet tmp = *bs; // storage used for the bitwise XOR
    // tmp = makeBitSet();
    tmp[&idx] = '1';
    // &bs = (bs ^ tmp); // XOR to set
    for (int i = 0; i < idx - 1; i++)
    {
        bs[i] = bs[i] ^ tmp[&i];
    }
}
// void clearBit(bitSet *bs, int index); // Sets bit 'index' of the bitset to 0
void clearBit(bitSet *bs, int idx)
{
    /*
    // bitSet tmp[sizeof(bs)]; // storage used for the bitwise XOR
    // tmp[idx] = '0';
    bitSet tmp = makeBitSet();
    tmp = *bs;
    // bs = (*bs & *tmp); // AND to clear
    // *bs = (*bs & tmp); // AND to clear
    // bs = (unsigned short)(*bs & tmp); // AND to clear
    // &bs = bs & tmp;  // AND to clear
    */
}
// int bitValue(bitSet bs, int index);   // Returns the value of the bit at 'index'
int bitValue(bitSet bs, int idx)
{
    return *(&bs + idx); // returns value at given index of the bit set
}
