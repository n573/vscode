#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Nathan Cauwet
 */

typedef struct freq
{
    char *v;
    int f;
} histogram;

void displayScores(char **arr, int size)
{
    printf("Displaying:\n");
    for (int i = 0; i < size; i++)
    {
        printf("score %d:%s\n", i, arr[i]);
    }
    printf("\n");
}

char **readScores(int *num)
{
    int i = 0;
    char *x = (char *)malloc(50 * sizeof(char));
    char **arr = (char **)malloc(100 * sizeof(char *));
    while (scanf("%s", x) != EOF)
    {
        *(arr + i) = (char *)malloc((strlen(x) + 1 * sizeof(char)));
        strcpy(*(arr + i), x);
        *num += 1;
        i++;
    }
    free(x);
    return arr;
}

void displayHistogram(histogram **sortArr, int size)
{
    printf("Display Histogram:\n");
    for (int i = 0; i < size; i++)
    {
        printf("value = \"%s\": freq = %d\n", sortArr[i]->v, sortArr[i]->f);
    }
}

void sortHistogram(histogram **sortArr, int size) // sorts into ascending order
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (sortArr[j]->f > sortArr[i]->f)
            {
                histogram *temp = sortArr[i];
                sortArr[i] = sortArr[j];
                sortArr[j] = temp;
            }
        }
    }
}

int calcHistogram(histogram ***sortArr, int size, char **scoresArr) // calculates freq
{
    *sortArr = (histogram **)malloc(100 * sizeof(histogram *));
    int found = 0;
    int sortsize = 0;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        found = 0;
        j = 0;
        while (j < sortsize && found != 1)
        {
            if (strcmp(scoresArr[i], (*sortArr)[j]->v) == 0)
            {
                (*sortArr)[j]->f += 1;
                found = 1;
                free(scoresArr[i]);
            }
            j++;
        }
        if (found != 1)
        {
            (*sortArr)[sortsize] = (histogram *)malloc(size * sizeof(histogram));
            (*sortArr)[sortsize]->v = scoresArr[i];
            (*sortArr)[sortsize]->f = 1;
            sortsize++;
        }
    }
    free(scoresArr);
    return sortsize;
}

int main()
{
    histogram **sortArr;
    int numScores = 0;
    int histSize = 0;
    char **scoresArr = readScores(&numScores);

    displayScores(scoresArr, numScores);
    numScores = calcHistogram(&sortArr, numScores, scoresArr);

    displayHistogram(sortArr, numScores);
    sortHistogram(sortArr, numScores);
    printf("\nSorted Histogram ");
    displayHistogram(sortArr, numScores);
    return 0;
}
