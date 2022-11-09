# include <stdlib.h>
# include <stdio.h>
# include <omp.h>

int main ( int argc, char *argv[] );
void prime_number_sweep ( int n_lo, int n_hi, int n_factor );
int prime_number ( int n );

/******************************************************************************/

int main ( int argc, char *argv[] )


{
  int n_factor;
  int n_hi;
  int n_lo;

  printf ( "\n" );
  printf ( "PRIME_OPENMP\n" );
  printf ( "  C/OpenMP version\n" );

  printf ( "\n" );
  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );

  n_lo = 10;
  n_hi = 100;
  n_factor = 2;

  prime_number_sweep ( n_lo, n_hi, n_factor );

  n_lo = 10;
  n_hi = 100;
  n_factor = 10;

  prime_number_sweep ( n_lo, n_hi, n_factor );
  /*
  Terminate.
  */
  printf ( "\n" );
  printf ( "PRIME_OPENMP\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
/******************************************************************************/

void prime_number_sweep ( int n_lo, int n_hi, int n_factor )


{
  int n;
  int primes;
  double wtime;
  //  double start;
  // double end;
  
  printf ( "\n" );
  printf ( "TEST01\n" );
  printf ( "  Call PRIME_NUMBER to count the primes from 1 to N.\n" );
  printf ( "\n" );
  printf ( "         N        Pi          Time\n" );
  printf ( "\n" );

  n = n_lo;

  while ( n <= n_hi )
    {
      // start = omp_get_wtime ( );

      primes = prime_number ( n );

      // end = omp_get_wtime ();

      wtime = omp_get_wtime () - wtime;

      //  wtime = end - start;
      
      printf ( "  %8d  %8d  %14f\n", n, primes, wtime );

      n = n * n_factor;
    }

  return;
}
/******************************************************************************/

int prime_number ( int n )


{
  int i;
  int j;
  int prime;
  int total = 0;

  # pragma omp parallel \
    shared ( n ) \
    private ( i, j, prime )


# pragma omp for reduction ( + : total )
  for ( i = 2; i <= n; i++ )
    {
      prime = 1;

      for ( j = 2; j < i; j++ )
	{
	  if ( i % j == 0 )
	    {
	      prime = 0;
	      break;
	    }
	}
      total = total + prime;
    }

  return total;
}
