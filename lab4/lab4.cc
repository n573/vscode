#include <iostream>
#include <stdlib.h>
#include <thread>

// Nathan Cauwet

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

int *

    int
    main()
{
    int tStart = 10;
    int tEnd = 100;
    int amount = 0;
    int n = 5;
    int t[] = {tStart, tEnd};

    if (n <= 1)
    {
        std::cout << "first prime is 2, input was 0, 1, or negative (therefore N/A)" << n << "\n";
    }

    int nThreads = 4;
    std::thread *ths[nThreads];

    int *ifPrime = (int *)malloc(nThreads * sizeof(int));

    for (int i = 0; i < nThreads; i++)
    {
        ifPrime[i] = 0;
    }

    for (int i = 0; i < nThreads; i++)
    {

        int dist = t[1] - t[0];
        int start = ((dist / nThreads) * i) + t[0];
        int stop = ((dist / nThreads) * (i + 1)) + t[0];

        if (i == (nThreads - 1))
        {
            stop += dist % nThreads;
        }

        std::thread *th = new std::thread(runProc, start, stop, i, ifPrime);
        ths[i] = th;
        std::cout << "threads " << i << ": " << start << "-" << stop << "\n";
    }
    for (int i = 0; i < nThreads; i++)
    {
        ths[i]->join();
    }
    for (int i = 0; i < nThreads; i++)
    {
        amount += ifPrime[i];
        std::cout << "amount: " << amount << "\n";
    }
    std::cout << "there are " << amount << " of primes between " << tStart << " & " << tEnd << "\n";
    free(ifPrime);
}
