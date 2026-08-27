#include "../stack.hpp"
#include "catch/catch.hpp"

TEST_CASE("Test default Node (next)") {
  Node n(50);

  SECTION("Default next is nullptr") {
    CHECK(50 == n.getValue());
    CHECK(nullptr == n.getNext());
  }

  SECTION("Set next") {
    Node* next = new Node(30);
    n.setNext(next);
    CHECK(next == n.getNext());
    delete next;
  }
}
