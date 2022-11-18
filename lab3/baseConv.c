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
    // for (int k = strlen(bin); k > -1; k--)
    {
        // if (strcmp(&bin[k], "0") == 0)
        if (bin[k] == '0')
        {
            arr[k] = 0;
        }
        // else if (strcmp(&bin[k], "1") == 0)
        else if (bin[k] == '1')
        {
            arr[k] = 1;
        }
        // else
        // {
        //     printf("test\n");
        // }
        // arr[k] = (int)bin[k];
        // printf("%d", arr[k]);
    }

    // for (int i = 0; i < strlen(bin); i++) // for (int i = 0; i < strlen(in); i++)
    // {
    //     // if(in[i] == 1) { }
    //     tmp += pow(2 * bin[i], i); // 2*(   // bitSet set = makeBitSet();
    //     // //// bitValue(set,)
    //     // int *dec = binToDec(&set);1 or 0)^i -- binary to decimal
    // }

    printf("\n");
    // for (int i = 0; i < strlen(bin); i++)
    for (int i = sizeof(arr); i > -1; i--)
    {
        // printf("%d", arr[i]);
        // out += arr[i] * (2 * i);
        // out += arr[i] * pow(2, i);
        if (arr[i] == 1)
        {
            out += arr[i] * pow(2, i);
            printf("%d\n", out);
        }
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

int baseToDec(int base, char *value)
{
    int dec = 0;
    for (int i = 0; i < sizeof(value); i++)
    {
        dec += pow((double)(base * value[i]), (double)i);
    }
    return dec;
}

char *decToBase(int base, int dec)
{
    // while (dec >= 2)
    int tmp;
    // char *out = '';
    char *out;
    int idx = 0;
    while (dec >= base)
    {
        tmp = dec % base;
        if (tmp != 0) // CHECK THIS OUTPUT
        {
            dec += dec / base;
            out[idx] = '1';
        }
        else if (tmp == 0)
        {
            out[idx] = '0';
        }
        else
        {
            printf("ERROR in decToBase");
        }
        idx++;
    }
    return out;
}
