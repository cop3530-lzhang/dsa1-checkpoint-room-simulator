#include "catch/catch.hpp"
#include "../seat.hpp"

TEST_CASE("Testing Seat constructors") {
  Seat s1;  // set default status to false
  CHECK(!s1.getStatus());

  Seat s2(true);
  CHECK(s2.getStatus());

  Seat s3(false);
  CHECK(!s3.getStatus());
}

TEST_CASE("Testing Seat methods") {
  Seat s;
  CHECK(!s.free()); // freeing an already free seat!

  CHECK(s.book()); // booking a free seat

  CHECK(s.getStatus());

  CHECK(!s.book()); // booking a booked seat!

  CHECK(s.free()); // freeing a booked seat!

  CHECK(!s.getStatus());
}
