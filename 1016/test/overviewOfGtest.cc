#include <gtest/gtest.h>

int Factorial(int n);

inline int Factorial(int n)
{
  int result;
  for(int i; i <= n; i++) {
    result *= i;
  }
  return result;
}
bool IsInRange(int value, int low, int high) {
  return low <= value && value <= high;
}

TEST(FactorialTest, HandlesPositiceInput) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(3, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}

TEST(Subject, HasCertainProperty) {
  EXPECT_TRUE(IsInRange(SomeFunction(), low, high)
      << "SomeFunction() = " << SomeFunction() << ", not in rage [" << low << ", " << high << "]";

      int result = SomeFunction();
      EXPECT_TRUE(IsInRange(result, low, high)
        << "result(return value of SomeFunction()) = " << result << ", not in rage [" << low << ", " << high << "]";

        AssertionResult IsInRange(int value, int low, int high) {
        if(value < low) {
        return AssertionFailure() << value << " < lower bound " << low;
        }
        else if(value > high) {
        return AssertionFailure() << value << " > upper bound " << high;
        }
        else {
        return AssertionSuccess() << value << " is in range [" << low << " , " << high << "]";
        }
        }
        }
