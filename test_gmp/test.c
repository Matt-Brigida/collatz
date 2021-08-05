#include <stdio.h>
#include <gmp.h>

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
