#include <limits>

#include "../stack.hpp"
#include "catch/catch.hpp"

TEST_CASE("class Stack") {
  Stack s;

  SECTION("Stack class push/pop") {
    CHECK(s.isEmpty());
    s.push(50);
    CHECK(!s.isEmpty());
    CHECK(50 == s.peek());
    CHECK(50 == s.pop());
    CHECK(s.isEmpty());
  }

  SECTION("Stack class consecutive push/pop") {
    s.push(10);
    s.push(20);
    s.push(30);
    // 30, 20, 10 from top to bottom

    CHECK(30 == s.pop());
    CHECK(20 == s.pop());
    CHECK(10 == s.pop());
    CHECK(s.isEmpty());
  }

}
