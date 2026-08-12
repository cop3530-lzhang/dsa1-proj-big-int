#include"expression-reader.hpp"

int main() {
  ExpressionReader er("test/expressions.txt");

  while (!er.isEmpty()) {
    std::cout << er.processNextExpression() << "\n----------\n";
  }
  return 0;
}
