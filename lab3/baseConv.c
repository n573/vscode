#include <string.h>
#include <math.h>
// #include "bitset.c"
// #include "lab3.c"

int binToDec(char *bin)
{
    int out = 0;
    // double tmp = 0;
    // char *in = &bin;
    int arr[strlen(bin)];
    for (int k = 0; k < strlen(bin); k++)
    {
        arr[k] = (int)bin[k];
    }

    // for (int i = 0; i < strlen(bin); i++) // for (int i = 0; i < strlen(in); i++)
    // {
    //     // if(in[i] == 1) { }
    //     tmp += pow(2 * bin[i], i); // 2*(   // bitSet set = makeBitSet();
    //     // //// bitValue(set,)
    //     // int *dec = binToDec(&set);1 or 0)^i -- binary to decimal
    // }

    for (int i = 0; i < strlen(bin); i++)
    {
        out += arr[i] * (2 * i);
    }

    return out;
}

// int binToDec(char *bin)
// {
//     int out;
//     // char *in = &bin;

//     for (int i = 0; i < strlen(bin); i++) // for (int i = 0; i < strlen(in); i++)
//     {
//         // if(in[i] == 1) { }
//         out += pow(2 * bin[i], i); // 2*(   // bitSet set = makeBitSet();
//         // //// bitValue(set,)
//         // int *dec = binToDec(&set);1 or 0)^i -- binary to decimal
//     }

//     return out;
// }
char *decToBin(int dec)
{
    char *bin;
    int tmp = dec;
    int itr;
    while (tmp != 0)
    {
        bin[itr] = tmp % 2;
        tmp = floor(tmp / 2);
        itr++;
    }
    return bin;
}

// int main()
// {

//     return 0;
// }