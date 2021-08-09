#include <stdio.h>
#include <gmp.h>

void collatz(mpz_t big_number, mpz_t return_value);

int
main(void)
{
 
  const char* big_num = "454353534483274829347329847298347928374982347293847293847239429342934299247";

  mpz_t return_value;
  mpz_init(return_value);

  collatz(big_num, return_value);

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
      mpz_cdiv_q(return_value, big_number, two);
    }
  else
    {
      mpz_mul_ui(return_value, big_number, 3);
      mpz_add_ui(return_value, return_value, 1);
    }
}
