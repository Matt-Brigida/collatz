#include <stdio.h>
#include <gmp.h>

void collatz(mpz_t big_number);

int
main(void)
{
    
  const char* big_num = "454353534483274829347329847298347928374982347293847293847239429342934299247";

  mpz_t big_number;
  mpz_init(big_number);
  mpz_set_str(big_number, big_num, 10);

  collatz(big_number);
  
}

void collatz(mpz_t big_number)
{

  int counter = 0;

  mpz_t two;
  mpz_init(two);
  mpz_set_si(two, 2);

  while(!(mpz_cmp_d(big_number, 1) == 0))
    {
      counter = counter + 1;
   if (mpz_even_p(big_number))
    {
      mpz_cdiv_q(big_number, big_number, two);
      collatz(big_number);
    }
   else 
    {
      mpz_mul_ui(big_number, big_number, 3);
      mpz_add_ui(big_number, big_number, 1);
      collatz(big_number);
    }
    }
    printf("The counter is: %d\n", counter);
}
    


/*** way to print big number
  void (*null_ptr)() = NULL;
  mpz_out_str(null_ptr,10, counter);
***/
