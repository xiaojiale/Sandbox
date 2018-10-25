#include <gtest/gtest.h>
#include <stdio.h>
int add(int, int);

TEST(Fun, Add)
{
  EXPECT_EQ(1, add(2, -1));
  EXPECT_EQ(5, add(2, 3));
}

int add(int val1, int val2)
{
  return val1 + val2;
}
