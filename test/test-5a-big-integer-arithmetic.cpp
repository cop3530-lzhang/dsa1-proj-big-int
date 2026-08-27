#include<sstream>

#include "catch/catch.hpp"
#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"

TEST_CASE("class BigIntegerArithmetic part a")
{
  SECTION("operandComp method") {
    ArithmeticExpression ae("100", "100", '+');
    BigIntegerArithmetic bia(ae);
    CHECK(0 == bia.operandComp("100", "100"));
    CHECK(0 == bia.operandComp("10912373984260", "10912373984260"));
    CHECK(0 < bia.operandComp("100", "99"));
    CHECK(0 > bia.operandComp("99", "100"));
    CHECK(0 < bia.operandComp("10912373984260", "99"));
    CHECK(0 > bia.operandComp("99", "10912373984260"));
  }

}