#include "test_framework/generic_test.h"
int Divide(int x, int y) {
  
  // x = 64 
  // y = 2 
  // quotient = 32
  // The number of subtractions is the quotient 

  // O(size of number)
  // Example: x = 99999999 and y = 1, that means we will run this loop
  // 99999999 times
  unsigned long long quotient = 0;
  while (x >= y) {
    x -= y;
    quotient++;
  }
  return quotient;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
