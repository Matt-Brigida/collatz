#include <stdio.h>
#include <gmp.h>

void collatz(mpz_t big_number);

int
main(void)
{
  mpz_t one;
  mpz_init(one);

  const char* big_num = "454353534483274829347329847298347928374982347293847293847239429342934299247";
  
  mpz_set_str(one, big_num, 10);

  mpz_add_ui(one, one, 1);

  void (*null_ptr)() = NULL;
  // int* null_ptr=NULL;
  mpz_out_str(null_ptr,10, one);
  return 0;
}

void collatz(mpz_t big_number)
{

  mpz_t is_divis;
  mpz_init(is_divis);

  mpz_t two;
  mpz_init(two);
  mpz_set_si(two, 2);

  mpz_t zero;
  mpz_init(zero);
  mpz_set_si(zero, 0);

  mpz_t return_value;
  mpz_init(return_value);

  if (mpz_mod_ui(is_divis, big_number, 2) == 0) {return mpz_cdiv_q(return_value, big_number, two);}
  else {return 3 * big_number + 1;}
}
