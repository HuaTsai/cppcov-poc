#include <add.hpp>
#include <gtest/gtest.h>
#include <minus.hpp>

TEST(AddMinusTest, Add) {
  Eigen::Vector2d a(1.0, 2.0);
  Eigen::Vector2d b(3.0, 4.0);
  Eigen::Vector2d c = Add(a, b);
  EXPECT_EQ(c(0), 4.0);
  EXPECT_EQ(c(1), 6.0);
}

TEST(AddMinusTest, Minus) {
  Eigen::Vector2d a(1.0, 2.0);
  Eigen::Vector2d b(3.0, 4.0);
  Eigen::Vector2d c = Minus(a, b);
  EXPECT_EQ(c(0), -2.0);
  EXPECT_EQ(c(1), -2.0);
}
