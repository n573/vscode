//Nathan Cauwet
#include <stdio.h>
#include <stdbool.h>//bool
#include <stdlib.h> //malloc


void readScores(int s[], int* num) {
    //int* b = malloc(10 * sizeof(int));//allocates memory in the heap instead of the runtime stack using malloc
    bool done = false;
    int i=0;
    while (!done) {
        //printf("Enter score %d: ", i);
        int score;
        //scanf("%d", &score);
	scanf("%d", &score);
        if (score == EOF) {
            done = true;
	    printf("done triggered at i=%d\n", i);
        } else {
	    printf("in: %d\n", score);
            s[i] = score;
            i++;
        }
    }
    *num = i;
    //return b;
}

void displayScores(int *scores, int numScores) {//no changes necessary
    for (int i=0; i<numScores; i++) {
        printf("Scores %d: %d\n", i, scores[i]);
    }
}

int main() {

    int scores[100];//we want to get rid of this
    int numScores;
    //scores = readScores(&numScores);//scores = b, numScores = num
    readScores(scores, &numScores);//numScores = num

    displayScores(scores, numScores);//displays

    return 0;
}
