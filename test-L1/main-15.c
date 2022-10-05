#include <stdio.h>

int readScores(int s[], int max) {
    int num = 0;//var for num of scores
    int in = 0;//input var
    for (int i = 0; i < max; i++) {

        printf("Enter score %d: ", i);
        scanf("%d", &in);
        s[i] = in;
        num++;

        if (s[i] == -1) {//exits if input = -1
            return num;//exits and returns num of scores
        }
    }
    return num;
}

void displayScores(int s[], int num) {
    for (int i = 0; i < num; i++) {
        if(s[i] != -1) {
            printf("Score %d: %d\n", i, s[i]);
        }
    }
}
int removeTarget(int s[], int num, int trgt) {
    for (int i = 0; i < num; i++) {
        if(s[i] == trgt) {//checks for target
            s[i] = s[i+1];//if the target is found, remove it and move up the following numbers
            for(int j = i; j < num; j++) {
                s[j] = s[j+1];//moves up remaining numbers
            }
            num = num - 1; //removes 1 from total number
        }
    }

    return num;//return new num scores
}

int main() {

    // Make array to hold up to max scores
    int max = 5;
    int scores[max];

    // Read in the scores - until max slots are filled or until a -1 is entered
    // returns the actual number of scores read and fills in the scores array
    int numOfScores = readScores(scores, max);

    // Display the scores
    displayScores(scores, numOfScores);

    // Read in a target
    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    // Remove the target
    // First find the index of the target
    // If the target doesn't exist then do nothing to the scores
    // If the target exists then bump all slots after it up one and
    //  adjust the numOfScores down by 1
    // Note that numOfScores needs to be returned since the number of
    //  scores may or may not be modified by the function
    numOfScores = removeTarget(scores, numOfScores, target);

    // Display the scores again
    displayScores(scores, numOfScores);

    return 0;
}