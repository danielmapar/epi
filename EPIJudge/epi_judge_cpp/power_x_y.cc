#include "test_framework/generic_test.h"
double Power(double x, int y) {

  if (y == 0) return 1;

  // O(size of y)
  unsigned long long timesToMultiply = y < 0 ? y * -1 : y;

  double pow = x;
  while (timesToMultiply > 1) {
    pow *= x;
    timesToMultiply--;
  }

  return y < 0 ? 1/pow : pow;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
