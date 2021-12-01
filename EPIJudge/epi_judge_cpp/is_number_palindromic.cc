#include "test_framework/generic_test.h"
bool IsPalindromeNumber(int x) {

  if (x < 0) return false;
  if (x >= 0 && x <= 9) return true;

  int reverseNumber = 0;
  int originalNumber = x;
  bool initialized = false;
  while (originalNumber > 0) {
    int rest = originalNumber >= 10 ? originalNumber % 10 : originalNumber;
    originalNumber = originalNumber >= 10 ? (originalNumber - rest) / 10 : originalNumber - rest;

    if (!initialized) {
      initialized = true;
      reverseNumber = rest;
      continue;
    }
    reverseNumber = (reverseNumber * 10) + rest;
  } 

  return reverseNumber == x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
