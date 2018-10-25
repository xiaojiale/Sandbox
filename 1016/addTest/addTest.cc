#include "add.h"
#include <gtest/gtest.h>

TEST(Add, Negative) {
  EXPECT_EQ(Add(-1, -2), -3);
  EXPECT_GT(Add(-4, -5), -6);
}

TEST(Add, Postive) {
  EXPECT_EQ(Add(1, 2), 3);
  EXPECT_GT(Add(4, 5), 6);
}

//int main(int argc, char* argv[])
//{
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}
