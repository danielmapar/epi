#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {

  unsigned long long result = 0UL;
  short bit = 0UL;
  // (sizeof = number of bytes) * (CHAR_BIT = 8 bits)
  short numOfBits = sizeof(result) * CHAR_BIT; 

  // O(n) --> n = size of var in bits
  while (numOfBits > 1) {
    bit = x & 1UL;

    result = result ^ bit;
    result <<= 1;

    x >>= 1;

    numOfBits--;
  }

  // Another option is to extract the left most bit
  // i & (1 << (sizeof(unsigned int) * CHAR_BIT - 1))

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
