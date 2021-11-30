#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {

  // x = 00001 = 1 --> 00010 -> 2
  // x = 00010 = 2 --> 00001 -> 1 /////
  // x = 00110 = 6 --> 00101 -> 5 //////
  // x = 00111 = 7 --> 01011 -> 10

  // if you find a 1 store its position 
  // if you find a 0 store its position 
  // store current index

  // CHAR_BIT = 8 bits
  // sizeof(unsigned long long) = 8 bytes
  signed int zeroIndex = -1;
  signed int oneIndex = -1;
  unsigned long long mask = 3UL; // 00011
  short bitStreamSize = CHAR_BIT * sizeof(unsigned long long);

  for (short index = 0; index < bitStreamSize; index++) {
    bool bit = (x>>index) & 1UL; // get right most bit
    if (bit == 0) {
      if (oneIndex > -1) {
        mask <<= oneIndex;
        break;
      }
      zeroIndex = index;
    } else { // bit = 1
      if (zeroIndex > -1) {
        mask <<= zeroIndex;
        break;
      }
      oneIndex = index;
    }
  }
  // std::cout << "mask = " << std::bitset<64>(mask) << std::endl;
  // std::cout << "x = " << std::bitset<64>(x) << std::endl;

  return x ^ mask;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
