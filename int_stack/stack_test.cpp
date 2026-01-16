#include "stack.hpp"

#include <cstddef>
#include <cstdint>

#include <catch2/catch_test_macros.hpp>

using std::size_t;

TEST_CASE("constructor", "[default-ctor]") {
  ds::Stack s;
  REQUIRE(s.size() == 0);
  REQUIRE(s.capacity() > 0);
}

TEST_CASE("push", "[push]") {
  ds::Stack s;

  SECTION("add a few elements") {
    s.push(5);
    REQUIRE(s.size() == 1);
    REQUIRE(s.capacity() >= 1);
    s.push(4);
    REQUIRE(s.size() == 2);
    REQUIRE(s.capacity() >= 2);
    s.push(3);
    REQUIRE(s.size() == 3);
    REQUIRE(s.capacity() >= 3);
    s.push(2);
    REQUIRE(s.size() == 4);
    REQUIRE(s.capacity() >= 4);
    s.push(1);
    REQUIRE(s.size() == 5);
    REQUIRE(s.capacity() >= 5);
  }

  // SECTION("add many elements") {
  //   constexpr size_t count = 300000;
  //   for (size_t i{0}; i < 300000; ++i) {
  //     s.push(static_cast<int64_t>(i));
  //   }
  //   REQUIRE(s.size() == count);
  //   REQUIRE(s.capacity() >= count);
  // }
}

// TEST_CASE("pop", "[pop]") {
//   ds::Stack s;
//
//   SECTION("pop a few elements") {
//     s.push(5);
//     s.push(4);
//     s.push(3);
//     s.push(2);
//     s.push(1);
//     REQUIRE(s.size() == 5);
//     REQUIRE(s.capacity() >= 5);
//     REQUIRE(s.pop() == 1);
//     REQUIRE(s.size() == 4);
//     REQUIRE(s.capacity() >= 5);
//     REQUIRE(s.pop() == 2);
//     REQUIRE(s.size() == 3);
//     REQUIRE(s.capacity() >= 5);
//     REQUIRE(s.pop() == 3);
//     REQUIRE(s.size() == 2);
//     REQUIRE(s.capacity() >= 5);
//     REQUIRE(s.pop() == 4);
//     REQUIRE(s.size() == 1);
//     REQUIRE(s.capacity() >= 5);
//     REQUIRE(s.pop() == 5);
//     REQUIRE(s.size() == 0);
//     REQUIRE(s.capacity() >= 5);
//   }

  // SECTION("remove many elements (shrinking)") {
  //   constexpr size_t count = 30000;
  //   for (size_t i{0}; i < 30000; ++i) {
  //     s.push(static_cast<int64_t>(i));
  //   }
  //
  //   size_t new_size = 5000;
  //   for (size_t i{count - 1}; i >= new_size; --i) {
  //     CHECK(s.pop() == static_cast<int64_t>(i));
  //   }
  //   REQUIRE(s.size() == new_size);
  //   REQUIRE(s.capacity() <= new_size * 4);
  //
  //   new_size = 200;
  //   for (size_t i{4999}; i >= new_size; --i) {
  //     CHECK(s.pop() == static_cast<int64_t>(i));
  //   }
  //   REQUIRE(s.size() == new_size);
  //   REQUIRE(s.capacity() <= new_size * 4);
  //
  //   for (size_t i{199}; i > 0; --i) {
  //     REQUIRE(s.pop() == static_cast<int64_t>(i));
  //   }
  //   REQUIRE(s.pop() == 0);
  //   REQUIRE(s.size() == 0);
  //   REQUIRE(s.capacity() == 10);
  // }
//}

