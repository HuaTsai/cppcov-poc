#include <add.hpp>
#include <iostream>
#include <minus.hpp>

void test_add() {
  Eigen::Vector2d a(1.0, 2.0);
  Eigen::Vector2d b(3.0, 4.0);
  Eigen::Vector2d c = Add(a, b);
  std::cout << "c = " << c.transpose() << "\n";
}

void test_minus() {
  Eigen::Vector2d a(1.0, 2.0);
  Eigen::Vector2d b(3.0, 4.0);
  Eigen::Vector2d c = Minus(a, b);
  std::cout << "c = " << c.transpose() << "\n";
}

int main() {
  std::cout << "Start main...\n";
  test_add();
  test_minus();
  std::cout << "Finished!\n";
}
