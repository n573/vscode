//Nathan Cauwet
#include <stdio.h>
#include <stdbool.h>//bool
#include <stdlib.h> //malloc


int* readScores(int* num) {//return type is int* and num points to numScores
    int* b = malloc(10 * sizeof(int));//allocates memory in the heap instead of the runtime stack using malloc
    bool done = false;
    int i=0;
    while (!done) {
        //printf("Enter score %d: ", i);
        int score;
        scanf("%d", &score);
        if (score == -1) {
            done = true;
        } else {
            b[i] = score;
            i++;
        }
    }
    * num = i;
    return b;
}

void displayScores(int *scores, int numScores) {//no changes necessary
    for (int i=0; i<numScores; i++) {
        printf("Scores %d: %d\n", i, scores[i]);
    }
}

int main() {

    //int scores[10];//we want to get rid of this
    int *scores;//array of unspecified size for storage
    int numScores;
    scores = readScores(&numScores);//scores = b, numScores = num

    displayScores(scores, numScores);//displays

    return 0;
}
