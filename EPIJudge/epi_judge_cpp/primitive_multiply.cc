#include "test_framework/generic_test.h"

unsigned long long add(unsigned long long sum, unsigned long long num) {

  // Simple example (3 + 3)
  // -----------------

  // 1 loop
  // sum = 00000011 = 3
  // num = 00000011 = 3
  
  // carry = num & sum = 00000011
  // sum = sum ^ num = 00000000 
  // num = carry < 1 = 00000110

  // 2 loop
  // carry = 00000110 & 00000000 = 00000000
  // sum = sum ^ num = 00000000 ^ 00000110 = 00000110
  // num = carry < 1 = 00000000

  // Simple example (3 + 1)
  // -----------------

  // 1 loop
  // sum = 00000011 = 3
  // num = 00000001 = 1
  
  // carry = num & sum = 00000001
  // sum = sum ^ num = 00000010 
  // num = carry < 1 = 00000010

  // 2 loop
  // carry = 00000010 & 00000010 = 00000010
  // sum = sum ^ num = 00000010 ^ 00000010 = 00000000
  // num = carry < 1 = 00000100

  // 3 loop
  // carry = 00000010 & 00000100 = 00000000
  // sum = sum ^ num = 00000000 ^ 00000100 = 00000100
  // num = carry < 1 = 00000000

  while (num) {
    unsigned long long carry = num & sum; // 0
    sum = sum ^ num;
    num = carry << 1;
  }
  return sum;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  
  unsigned long long sum = 0;
  while (x) {
    // Examines each bit of x.
    if (x & 1) {
      sum = add(sum, y);
    }
    // decrement X and increment Y
    x >>= 1; y <<= 1;
  }
  return sum;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
