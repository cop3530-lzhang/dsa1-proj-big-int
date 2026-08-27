#include <sstream>

#include "../arithmetic-expression.hpp"
#include "catch/catch.hpp"

TEST_CASE("class ArithmeticExpression") {
  ArithmeticExpression ae;
  ArithmeticExpression aeAdd("1234567", "23456", '+');
  ArithmeticExpression aeFirstNegative("-1234567", "23456", '+');
  ArithmeticExpression aeSubtract("1234567", "23456", '-');
  ArithmeticExpression aeAddNegative("1234567", "-23456", '+');
  ArithmeticExpression aeSubtractNegative("1234567", "-23456", '-');

  SECTION("Default constructor") {
    CHECK("" == ae.getOp1Str());
    CHECK("" == ae.getOp2Str());
    CHECK(' ' == ae.getOperator());
  }

  SECTION("Parameterized constructor") {

    CHECK("1234567" == aeAdd.getOp1Str());
    CHECK("23456" == aeAdd.getOp2Str());
    CHECK('+' == aeAdd.getOperator());

    CHECK("-1234567" == aeFirstNegative.getOp1Str());
    CHECK("23456" == aeFirstNegative.getOp2Str());
    CHECK('+' == aeFirstNegative.getOperator());

    CHECK("1234567" == aeSubtract.getOp1Str());
    CHECK("23456" == aeSubtract.getOp2Str());
    CHECK('-' == aeSubtract.getOperator());
  }

  SECTION("Second operand is negative, flip sign and change operator") {
    CHECK("1234567" == aeAddNegative.getOp1Str());
    CHECK("23456" == aeAddNegative.getOp2Str());
    CHECK('-' == aeAddNegative.getOperator());

    CHECK("1234567" == aeSubtractNegative.getOp1Str());
    CHECK("23456" == aeSubtractNegative.getOp2Str());
    CHECK('+' == aeSubtractNegative.getOperator());
  }

}
