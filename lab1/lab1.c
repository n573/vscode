#include <stdio.h>

void readScores(int s[], int *arrLen)
{
    int num = 0; // var for num of scores
    int in = 0;  // input var
    for (int i = 0; i < *arrLen; i++)
    {

        printf("Enter score %d: ", i);
        scanf("%d", &in);
        s[i] = in;
        num++;
        printf("%d", s[i]);
        if (s[i] == -1)
        {           // exits if input = -1
            return; // exits and returns num of scores
        }
    }
    arrLen = &num;
    s = *&s;
}

void displayScores(int s[], int num)
{
    for (int i = 0; i < num; i++)
    {
        if (s[i] != -1)
        {
            printf("Score %d: %d\n", i, s[i]);
        }
    }
}

int main()
{

    // Make array to hold up to max scores
    // int max = 100;
    // int scores[max];
    int scores[100];
    int numScores = 0;
    // Read in the scores - until max slots are filled or until a -1 is entered
    // returns the actual number of scores read and fills in the scores array
    // int numOfScores = readScores(scores, numScores);
    readScores(scores, &numScores);

    // Display the scores
    displayScores(scores, numScores);

    return 0;
}
