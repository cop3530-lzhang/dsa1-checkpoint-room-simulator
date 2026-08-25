#include "catch/catch.hpp"
#include "../room.hpp"

TEST_CASE("Testing Room constructors") {
  Room r1; // default should create 3x3 room
  CHECK(r1.getCols() == 3);
  CHECK(r1.getRows() == 3);

  Room r2(4, 5);
  CHECK(r2.getRows() == 4);
  CHECK(r2.getCols() == 5);
}

TEST_CASE("Testing Room Book/Free seats") {
  Room r1;
  CHECK(r1.bookSeat(1, 1)); // book seat within range
  CHECK(!r1.bookSeat(1, 1)); // book booked seat

  CHECK(!r1.bookSeat(4, 0)); // book seat outside range;
  CHECK(!r1.bookSeat(-1, 2)); // book seat outside range;

  CHECK(r1.freeSeat(1, 1)); // free booked seat
  CHECK(!r1.freeSeat(-1, 1)); // free out of range seat
  CHECK(!r1.freeSeat(0, 1)); // free empty seat
}
