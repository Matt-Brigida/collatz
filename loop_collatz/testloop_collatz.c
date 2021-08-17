#include <stdio.h>
#include <gmp.h>



int main(void) {

  const char* big_num = "100000000000000000000000000000000000000000000000000"; //start at 10^{50}

  mpz_t big_number;
  mpz_init(big_number);
  mpz_set_str(big_number, big_num, 10);

  const char* biggest_num = "100000000000000000000000000000000000000000000000009"; //start at 10^{50}

  mpz_t biggest_number;
  mpz_init(biggest_number);
  mpz_set_str(biggest_number, biggest_num, 10);


  for(big_number; mpz_cmp(big_number, biggest_number);mpz_add_ui(big_number, big_number, 1) ) {
    gmp_printf ("%s is an mpz %Zd\n", "here", big_number);
  }
}
