#include <sstream>

#include "../expression-reader.hpp"
#include "catch/catch.hpp"

TEST_CASE("class ExpressionReader") {
  ExpressionReader er("test/expressions.txt");

  CHECK("12 + 5 = 17" == er.processNextExpression());
  CHECK("5 + 12 = 17" == er.processNextExpression());
  CHECK("12 - 5 = 7" == er.processNextExpression());
  CHECK("5 - 12 = -7" == er.processNextExpression());
  CHECK(
      "364287463834623846283426384"
      " + 923742938742934723947239847"
      " = 1288030402577558570230666231"
        == er.processNextExpression());
  CHECK(
      "364287463834623846283426384"
      " - 923742938742934723947239847"
      " = -559455474908310877663813463" == er.processNextExpression());

  CHECK(er.isEmpty());
}
