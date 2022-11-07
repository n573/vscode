#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "duSocket.h"
#include <mutex>
#include <omp.h>
#include <pthread.h>
std::mutex screenLock;

int main(){
  int numThreads = 4;
  int termsStart = 10;
  int termsEnd = 15;
  int terms[] = {termsStart, termsEnd};
  int portNum = 8086;
  omp_set_num_threads(numThreads);
  
  setupServerSocket(portNum);

  for(int i = 0; i < numThreads; i++){

    s[i] = serverSocketAccept(serverNum );
    printf("GOT IT YEAAAAA\n");
  }
  for(int i = 0; i < numThreads; i++){
    int distance = terms[1] - terms[0];
    int start = ((distance / numThreads) * i) + terms[0];
    int stop = ((distance / numThreads) * (i + 1)) + terms[0];

    if(i==(numThreads - 1)){
      stop += distance % numThreads;
    }
    //write start and stop, read result. take result and add to total  

  }




  
}
