#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {

  // x = 64 bits
  // x = 00001001

  // Extract the bit
  long long iBit = (x >> i) & 1UL;
  long long jBit = (x >> j) & 1UL;
  
  if (iBit == jBit) return x;

  long long iInt = 1UL << j;
  long long jInt = 1UL << i;

  return x ^ (iInt | jInt);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
