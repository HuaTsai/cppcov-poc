#include <gtest/gtest.h>

#include <add.hpp>
#include <minus.hpp>

TEST(AddMinusTest, Add) {
  Eigen::Vector2d a(1.0, 2.0);
  Eigen::Vector2d b(3.0, 4.0);
  Eigen::Vector2d c = Add(a, b);
  EXPECT_EQ(c(0), 4.0);
  EXPECT_EQ(c(1), 6.0);
}

TEST(AddMinusTest, AddLarge) {
  Eigen::Vector2d a(100000.0, 200000.0);
  Eigen::Vector2d b(300000.0, 400000.0);
  Eigen::Vector2d c = Add(a, b);
  EXPECT_EQ(c(0), 400000.0);
  EXPECT_EQ(c(1), 600000.0);
}

TEST(AddMinusTest, Minus) {
  Eigen::Vector2d a(1.0, 2.0);
  Eigen::Vector2d b(3.0, 4.0);
  Eigen::Vector2d c = Minus(a, b);
  EXPECT_EQ(c(0), -2.0);
  EXPECT_EQ(c(1), -2.0);
}

TEST(AddMinusTest, MinusLarge) {
  Eigen::Vector2d a(100000.0, 200000.0);
  Eigen::Vector2d b(300000.0, 400000.0);
  Eigen::Vector2d c = Minus(a, b);
  EXPECT_EQ(c(0), -200000.0);
  EXPECT_EQ(c(1), -200000.0);
}
