#include <stdio.h>

void readScores(int* arr, int arrLen) {
    // int in; 
    // while(in != EOF) {
    //     scanf('%d', &in);
    // }
    while(arr[arrLen] != EOF) {
        scanf("%d", &arr[arrLen]);
        arrLen++;
    // int in; 
    // while(in != EOF) {
    //     scanf('%d', &in);
    }
    

}

void displayScores() {

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
    int numScore=0;

    readScores(*scores, numScore);
    


    // printf("Hello, World!\n");
    return 0;
}
