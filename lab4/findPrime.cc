#include <iostream>
#include <stdlib.h>
#include <thread>

bool isPrime(int n)
{
    bool flag = false;               // triggers when a prime is found
    for (int i = 2; i <= n / 2; i++) // 2 is the first possible prime
    {
        if (n % i == 0)
        {
            flag = true;
            return flag;
        }
    }
    return flag;
}

void runProc(int start, int stop, int tnum, int *ifPrime)
{
    while (start != stop)
    {
        if (!isPrime(start))
        {
            ifPrime[tnum]++;
        }
        start++;
    }
}