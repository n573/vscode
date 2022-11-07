#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "duSocket.h"

int main(){
  int arePrime = 0;

  printf("about to call\n");
  int socketInt = callServer("localhost", 8086);
  // callServer("localhost", 5498);
  printf("connected\n");

  int start = readInt(socketInt);
  int stop = readInt(socketInt);

  while(start != stop){
    if(isPrime(start) == 1){
      arePrime++;
    }
    start++;
  }

  writeInt(arePrime, socketInt);

  close(socketInt);

}

int isPrime(int num){
  int prime = 0;//0 is false
  for(int i = 2; i<=/2;i++){
    if(num%i == 0){
      prime = 1;
      return prime;
    }
  }
  return prime;
}
