#include "../operand.hpp"
#include "catch/catch.hpp"

TEST_CASE("class Operand") {
  Operand empty;
  Operand o1("1234567");
  Operand o2("-1234567");
  Operand o3("+1234567");

  SECTION("Default constructor") {
    CHECK(!empty.isNegative());
    CHECK("" == empty.getValue());
  }

  SECTION("Constructor with value") {
    CHECK(!o1.isNegative());
    CHECK("1234567" == o1.getValue());
    CHECK(o2.isNegative());
    CHECK("-1234567" == o2.getValue());
    CHECK(!o3.isNegative());
    CHECK("1234567" == o3.getValue());
  }

  SECTION("setValue method") {
    empty.setValue("1234567");
    CHECK(!empty.isNegative());
    CHECK("1234567" == empty.getValue());

    // long integers
    empty.setValue("76567840346789678565785986759874321");
    CHECK("76567840346789678565785986759874321" == empty.getValue());
    empty.setValue("-76567840346789678565785986759874321");
    CHECK(empty.isNegative());
    CHECK("-76567840346789678565785986759874321" == empty.getValue());
  }

  SECTION("flipSign method") {
    CHECK(!o1.isNegative());
    o1.flipSign();
    CHECK(o1.isNegative());
    CHECK("-1234567" == o1.getValue());
    o1.flipSign();
    CHECK(!o1.isNegative());
    CHECK("1234567" == o1.getValue());
  }

}
