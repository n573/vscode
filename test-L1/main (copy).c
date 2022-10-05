// Nathan Cauwet
#include <stdio.h>
#include <stdbool.h> //bool
#include <stdlib.h>  //malloc

void readScores(int *s, int *num)
{
    s[100];
    bool done = false;
    int i = 0;
    while (!done)
    {
        int score;
        scanf("%d", &score);
        if (score == EOF)
        {
            done = true;
            // printf("done triggered at i=%d\n", i);
        }
        else
        {
            printf("in: %d\n", score);
            s[i] = score;
            i++;
        }
    }
    *num = i;
}

void displayScores(int *scores, int numScores)
{ // no changes necessary
    for (int i = 0; i < numScores; i++)
    {
        printf("Scores %d: %d\n", i, scores[i]);
    }
}

void calcHistogram(int *s, int max)
{
    struct Freq
    {
        int score;
        int count;
    } freq;

    struct Freq *farr;
    // freq.count = 0;

    int unique = 0;
    for (int i = 0; i < max - 1; i++)
    {
        farr[i].score = s[i];
        for (int j = 1; j < max; j++)
        {
            if (s[i] == s[j])
            {
                unique++;
            }
        }
        farr[i].count = unique;
    }
    // freq h[unique];

    //    freq h[];
}

int main()
{

    int scores[100]; // we want to get rid of this
    int numScores;

    readScores(scores, &numScores); // numScores = num

    displayScores(scores, numScores); // displays

    //calcHistogram(scores, numScores);

    return 0;
}
