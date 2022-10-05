#include <stdio.h>

void readScores(int* arr[], int arrLen) {
    scanf("%d", arr[0]);
    arrLen++;
    for(int i=1; i<sizeof(*arr); i++) {
    // for((int i=0; i<arrLen; i++;) && arr[i]==EOF) {
        if(*arr[i] != EOF) {
            scanf("%d", arr[i]);
            arrLen++;
        }
        // scanf("%d", &arr[i]);
        // arrLen++;
        // if(arr[i] == EOF) {
        //     return; // not the best method but should work
        // }
    }


    // int in;
    // while(arr[arrLen]!=EOF) { 
    //     scanf("%d", &in);
    //     arr[arrLen] = in;
    //     arrLen++;
    // }

    // int in; 
    // while(in != EOF) {
    //     scanf('%d', &in);
    // }
    /*
    while(*arr[arrLen] != EOF) {
        //scanf("%d", arr[arrLen]);
        scanf("%d", arr[arrLen]);
        arrLen++;
        printf("%d at %d", *arr[arrLen], arrLen);
    // int in; 
    // while(in != EOF) {
    //     scanf('%d', &in);
    }
    */

}

void displayScores(int arr[], int len) {

    for(int i=0; i<len; i++) {
        if(arr[i] != EOF) {
            printf("score %d: %d\n", i, arr[i]);

        }

    }

}

void calcHistogram() {

}

void displayHistogram() {

}

void sortHistogram() {

}

int main() {
    // int* scoreList;
    // int scores[100];
    int* scores[100];
    int numScore;

    readScores(scores, numScore);

    displayScores(*scores, numScore);

    return 0;
}
