#include <stdio.h>
int main(){
  int n, i, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  for (i = 2; i <= n / 2; ++i) {

    if ( n % i == 0) {
      flag = 1;
      break;
    }
  }

  if ( n == 1 ) {
    printf ( "1 isn't prime or composite whoops\n");
  }
  else {
    if ( flag == 0 )
      printf ( "%d is a prime number\n", n);
    else
      printf ( "%d is not prime\n", n);
  }
  return 0;
}
