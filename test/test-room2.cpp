#include "catch/catch.hpp"
#include "../room.hpp"


TEST_CASE("Testing Room Occupancy")
{
	Room r3(2,5);
	CHECK(Approx(0.0) == r3.occupancy());

  r3.bookSeat(0, 0);
  r3.bookSeat(0, 1);
	CHECK(Approx(0.2) == r3.occupancy());

  r3.bookSeat(0, 0); // book an already booked seat
	CHECK(Approx(0.2) == r3.occupancy());

  r3.bookSeat(1, 0);
	CHECK(Approx(0.3) == r3.occupancy());
}
