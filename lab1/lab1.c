// Nathan Cauwet
#include <stdio.h>
#include <limits.h>

struct freq
{
    int val;
    int idx;
};

void readScores(int *s, int *num)
{
    int temp;
    int i = 0;
    while (scanf("%d", &temp) != EOF)
    {
        if (temp > INT_MIN)
        {
            s[i] = temp;
            *num += 1;
            i++;
        }
        // if (temp > INT_MIN)
        // {
        //     s[i] = temp;
        //     *idx += 1;
        //     i++;
        // }
    }
}

// void displayScores(int *scores, int numScores)
// {
//     for (int i = 0; i < numScores; i++)
//     {
//         printf("Scores %d: %d\n", i, scores[i]);
//     }
// }

void displayScore(int s[], int idx)
{
    for (int i = 0; i < idx; i++)
    {
        printf("score %d: %d\n", i, s[i]);
    }
}
/*
void calcHistogram(int *s, int max)
{
    struct Freq
    {
        int score;
        int idx;
    } freq;

    struct Freq *fs;
    // freq.idx = 0;

    int unique = 0;
    for (int i = 0; i < max - 1; i++)
    {
        fs[i].score = s[i];
        for (int j = 1; j < max; j++)
        {
            if (s[i] == s[j])
            {
                unique++;
            }
        }
        fs[i].idx = unique;
    }
    // freq h[unique];

    //    freq h[];
}*/

void calcHist(struct freq *freqH, int *dist, int s[], int idx)
{
    short int inc[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < idx; i++)
    {
        if (inc[s[i] - 1])
        {
            for (int j = 0; j < *dist; j++)
                if (freqH[j].val == s[i])
                {
                    freqH[j].idx++;
                    break;
                }
        }
        else
        {
            freqH[*dist].val = s[i];
            freqH[*dist].idx = 1;
            inc[s[i] - 1] = 1;
            *dist += 1;
        }
    }
}
void displayHist(struct freq freqH[], int dist)
{
    for (int i = 0; i < dist; i++)
    {
        printf("\nvalue %d: freq %d", freqH[i].val, freqH[i].idx);
    }
}
void sortHist(struct freq *freqH, int dist)
{
    for (int i = 0; i < dist - 1; i++)
    {
        int max = freqH[i].idx, ind = i;
        for (int j = i + 1; j < dist; j++)
        {
            if (freqH[j].idx > max)
            {
                max = freqH[j].idx;
                ind = j;
            }
        }
        struct freq t = freqH[i];
        freqH[i] = freqH[ind];
        freqH[ind] = t;
    }
}

int main()
{
    int scores[100], count, dist;
    struct freq freqH[10];

    count = 0;
    readScores(scores, &count);
    displayScore(scores, count);

    dist = 0;
    calcHist(freqH, &dist, scores, count);
    printf("\nHistogram --");
    displayHist(freqH, dist);
    sortHist(freqH, dist);
    printf("\nSorted Histogram --");
    displayHist(freqH, dist);
    printf("\n");
    return 0;
}

/*
int main()
{

    int scores[100]; // we want to get rid of this
    int numScores;

    readScoress(scores, &numScores); // numScores = num

    displayScores(scores, numScores); // displays

    // calcHistogram(scores, numScores);

    return 0;
}
*/