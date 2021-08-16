#include <stdio.h>
#include <gmp.h>

void collatz(mpz_t big_number, int *counter);

int
main(void)
{

  int counter = 0;
    
  const char* big_num = "100000000000000000000000000000000000000000000000000"; //start at 10^{50}

  mpz_t big_number;
  mpz_init(big_number);
  mpz_set_str(big_number, big_num, 10);

  collatz(big_number, &counter);

  printf("The counter is: %d\n", counter);
  
}

void collatz(mpz_t big_number, int *counter)
{

  mpz_t two;
  mpz_init(two);
  mpz_set_si(two, 2);

  while(!(mpz_cmp_d(big_number, 1) == 0))
    {
      *counter = *counter + 1;
   if (mpz_even_p(big_number))
    {
      /* void (*null_ptr)() = NULL; */
      /* mpz_out_str(null_ptr,10, big_number); */
      gmp_printf ("Collatz number %Zd\n", big_number);

      mpz_cdiv_q(big_number, big_number, two);
      collatz(big_number, counter);
    }
   else 
    {
      /* void (*null_ptr)() = NULL; */
      /* mpz_out_str(null_ptr,10, big_number); */
      gmp_printf ("Collatz number %Zd\n", big_number);

      mpz_mul_ui(big_number, big_number, 3);
      mpz_add_ui(big_number, big_number, 1);
      collatz(big_number, counter);
    }
    }
}




/***
https://stackoverflow.com/questions/46422668/in-c-language-can-i-access-local-variable-of-main-function-in-another-function
***/
