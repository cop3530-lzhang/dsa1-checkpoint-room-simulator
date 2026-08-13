# Programming Checkpoint 1: Room simulator

## Programming Checkpoint Outcomes:
Develop C++ classes that uses:

- Modular compilation
- Multiple classes
- Two dimensional array
- Memory management
- UML class diagram

## Preparatory Readings:
- ZyBook primer chapters

## This Programming Checkpoint project

In this programming checkpoint, you will be required to create two classes to
model a seat and a room respectively. These classes can be used to create a
room simulator, which will not be part of this assignment.

### Project Requirements:
You are provided with a test suite in the folder [test/](test/). Your
implementation must pass all tests provided in this test suite:

1. The test suites are:

    1. [test-seat](test/test-seat.cpp) - This tests the functions of a seat
       object.
    1. [test-room1](test/test-room1.cpp) - This tests some functions of a room
       object.
    1. [test-room2](test/test-room2.cpp) - This tests some other functions of a
       room object.

    Room test suite is broken into two sets for grading purposes.

1. Running all of these tests must pass by running the command `make test-all`.
1. **You will lose points if memory leaks exist.**

## Code organizations

This project should be organized as two classes in four files: seat.hpp,
seat.cpp, room.hpp, room.cpp. **Do not write main.cpp or other test drivers!**

You should follow the UML and the instruction to decide the implementation of
the classes. You can also read tests in the [test/](test/) directory for more
information if needed.

### UML class diagrams
The class diagram is in the PlantUML format. The green circle means public while
red square means private. Hollow icon means instance variable while solid icon
means methods. You can check this [document][1] for more information.

[1]: https://plantuml.com/class-diagram#3644720244dd6c6a

![UML of Seat class](http://www.plantuml.com/plantuml/png/SoWkIImgAStDuKhEIImkLWXEJInHgERILKZApyzH04gMb1PpQOE5DJHX32Gva1Y82oAoDU2yjABKL0GlFRKa6AmQA5JBvP2QbmAq4000)

Text version for accessibility (- means private, + means public):
```
class Seat {
- bool status
+ Seat()
+ Seat(bool status)
+ bool book()
+ bool free()
+ bool getStatus()
}
```

### Seat class
- Default constructor should set the status to `false`
- Parameterized constructor to set the initial status
- Create a getter for `status` field
- The `book` method should return false if fails. It should fail if the seat is
  already booked. This method should also change status to `true` when it is
  successful.
- The `free` method should return false if fails. It should fail if the seat is
  already empty. This method should also change status to `false` when it is
  successful.

![UML of Room class](http://www.plantuml.com/plantuml/png/ROz13i8W44Ntd6AMfUeTcdY3UW9AHrEbZ66666Fqx0urL1TkOFZlvGCTYqkIvs1ySCpG4ytmC3iue1DeMzQDzJX5WKItEdeAR3QBtTWwL6UxAWMzLgca9vHUbSOgZopVTA_wJpeGXR9SoZkMvkbJUxQL7XFYNpfI7W82UP-lBlgxNluq7SPHl_a6)

Text version for accessibility (- means private, + means public):
```
class Room {
- Seat **seats
- int rows
- int cols
+ Room()
+ Room(int rows, int cols)
+ ~Room()
+ int getRows() const
+ int getCols() const
+ bool bookSeat(int i, int j)
+ bool freeSeat(int i, int j)
+ double occupancy()
}
```

### Room class
- The `seats` property is used to refer to a two dimensional array of `Seat`
  class objects
- Default constructor should set the rows and cols both to 3 as the default
  room dimension. It should allocate memory for the `seats` array
- Parameterized constructor to set the initial dimension and allocate memory
  for the `seats` array
- The destructor should release the memory to avoid **memory leak**
- Create getters for `rows` and `cols` fields
- The `bookSeat` method should fail when the designated location is out of the
  range. It can delegate the work to the `book()` method of the `Seat` class
  and return its returned value.
- The `freeSeat` method should fail when the designated location is out of the
  range. It can delegate the work to the `free()` method of the `Seat` class
  and return its returned value.
- The `occupancy` methods calculates the current occupancy rate. It is the
  quotient of the number of booked seats and the number of total seats. **Make
  sure that you will return an accurate ratio as a double value.** Avoid
  integer division!

## Implementation Notes:

Your application must function as described below:
1. Your program must adhere to the class descriptions provided in this README.
1. Your program must compile and pass tests.
   - All tests must pass by running together with `make test-all`. You can run
     individual test during development.
1. Your classes must be memory leak free. Memory leakage will be checked and
   graded in autograding.

## Building and Testing

A `Makefile` is provided to automate compilation and testing:
- **Run all unit tests**: `make test-all`
- **Run individual unit tests**:
  - `make test-seat`: Runs Seat class unit tests.
  - `make test-room1`: Runs Room class unit tests part 1.
  - `make test-room2`: Runs Room class unit tests part 2.
- **Run memory leak check**: `make test-mem` (runs Valgrind on the room2 test executable).
- **Clean build artifacts**: `make clean`

> **Note for macOS / Xcode users**: Valgrind is not natively supported on macOS. If you are using macOS command line tools (Xcode), you cannot directly execute `valgrind` / `make test-mem` locally. Please launch a **GitHub Codespaces** instance on GitHub (or use a Linux container) to run memory leak checks.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects
  received after that time will get a penalty or zero.
- Never change the test files! The results you get will be pointless as they
  will not align with our grading.
- Never change the makefile unless you are asked to do so
- Please review the academic honesty policy.
  - Note that viewing another student's solution, whether in whole or in part,
    is considered academic dishonesty.
  - Also note that submitting code obtained through the Internet or other
    sources, whether in whole or in part, is considered academic dishonesty.
    **All programs submitted will be reviewed for evidence of academic
    dishonesty, and all violations will be handled accordingly**.

## Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted"
   the assignment.
    1. After pushing, with `git push origin main`, visit the web URL of your
       repository to verify that your code is there. If you don't see the code
       there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your
   score for your submission.
    1. The auto-grading build should begin automatically when you push your code
       to GitHub.
    2. If your program will not compile, the graders will not be responsible for
       trying to test it.
    3. You should get an email regarding the status of your build, if it does
       not pass, keep trying.

## Grading Information:
- Breakdown
  + 50 pts GitHub Auto-grading
    * 10 pts test-seat
    * 20 pts test-room1
    * 10 pts test-room2
    * 10 pts memory leak check

## Checking Auto-grading Results:

After you push your code, GitHub will automatically run tests on your
submission. To view the results:

1. On your GitHub repository page, click the :arrow_forward: **Actions** tab at
   the top
2. Click on the most recent workflow run (it will show your commit message)
3. Wait until the run finishes (showing either ✅ or ❌)
4. Scroll down to "Autograding summary" section to see the summary
5. It will display:
   - **Points:** Your score (e.g., 10/10)
   - ✅ All tests passed! or ❌ Some tests failed
6. If tests failed, click the "Autograding" button above to see detailed logs:
   - Expand the **education/autograding@v1** step to see which tests failed
   - Look for :x: marks to identify specific failures

