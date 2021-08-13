#include <stdio.h>
#include <gmp.h>

void collatz(mpz_t big_number, mpz_t return_value);

int
main(void)
{

  int counter = 0;
 
  const char* big_num = "454353534483274829347329847298347928374982347293847293847239429342934299247";

  mpz_t big_number;
  mpz_init(big_number);
  mpz_set_str(big_number, big_num, 10);

  mpz_t return_value;
  mpz_init(return_value);

  collatz(big_number, return_value);

  void (*null_ptr)() = NULL;
  // int* null_ptr=NULL;
  mpz_out_str(null_ptr,10, return_value);
  return 0;
}

void collatz(mpz_t big_number, mpz_t return_value)
{

  mpz_t two;
  mpz_init(two);
  mpz_set_si(two, 2);
  
  if (mpz_even_p(big_number))
    {
      mpz_cdiv_q(&return_value, big_number, two);
    }
  else
    {
      mpz_mul_ui(&return_value, big_number, 3);
      mpz_add_ui(&return_value, return_value, 1);
    }
}
