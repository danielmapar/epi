#include "test_framework/generic_test.h"

short CountBits(unsigned int x) {
  // x = 2 -> 0010
  int num_of_bits = 0;
  while(x) {
    num_of_bits += x & 1; // 0010 & 0001 = 0000
    x = x >> 1; // from 0010 to 0001
  }
  return num_of_bits;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
