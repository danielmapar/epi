#include "test_framework/generic_test.h"
long long Reverse(int x) {
  // TODO - you fill in here.

  // 24 % 10 = 4 (rest)
  // 24 - rest = 20
  // 20 / 10 = 2
  bool negativeNumber = false;
  if (x < 0) {
    x *= -1;
    negativeNumber = true;
  }

  long long reverse = 0;
  bool initialized = false;
  while (x > 0) {
    int rest = x >= 10 ? x % 10 : x; // 24 --> rest = 4
    int newNumber = x - rest; // 24 - 4 --> newNumber = 20
    x = newNumber >= 10 ? newNumber / 10 : newNumber; // 20 >= 10 --> 20/10 = 2

    if (initialized == false) {
      initialized = true;
      reverse = rest;
      continue;
    }
    reverse *= 10;
    reverse += rest;
  }
  
  return negativeNumber ? reverse * -1 : reverse;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
