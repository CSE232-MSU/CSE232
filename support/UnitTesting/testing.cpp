// This is a test of the CSE 232 unit testing framework.

#include <iostream>

#include "testing.hpp"

double SquareRoot(double x) { return x / 2.0; }

int main()
{
  std::cout << "Testing." << std::endl;

  // Available detail levels:
  //  SILENT - no automatic output
  //  SUMMARY - output only at the end, indicating number of passed tests for each case.
  //  NORMAL - output with failed test cases and summary info at end.
  //  VERBOSE - output for all test cases (passed or failed) and summary info
  //  DEBUG - full internal detail to audit test cases and checks.
  SET_HIDDEN_DETAIL(SUMMARY);
  SET_PUBLIC_DETAIL(NORMAL);

  // Setup filenames to output specific information to files.
  SET_GRADE_FILE("grade.txt");       // A single number with the final numerical grade.
  SET_STUDENT_FILE("results.html");  // An html-formatted file with student feedback.
  SET_TEACHER_FILE("teacher-only.html");  // An html-formatted file with student feedback.

  TEST_CASE("Simple Tests", 10.0);  // A 10-point test case.

  size_t x = 5;
  size_t y = 8;
  CHECK(x + 2 < y+1, "This is an error message.");

  std::string str = "Test string.";
  std::string error_middle = " multi-segment";
  CHECK(str == "Test string.", "This is an error message for a", error_middle, " string test.");

  CHECK(str == "Test string2.", "This is an error message for a string test that should fail.");


  HIDDEN_TEST_CASE("Hidden Tests", 40.0);  // A 40-point hidden test case.

  CHECK(SquareRoot(4.0) == 2.0);
  CHECK(SquareRoot(16.0) == 4.0);
  CHECK(SquareRoot(1000000.0) == 1000.0, "Fails when tested on large values.");
  CHECK(SquareRoot(0.0) == 0.0, "Fails when tested on ZERO.");


  TEST_CASE("Free Points", 50.0);

  CHECK( 2+2 == 4);
  CHECK( true );
  CHECK( "abc" == "abc");


  TEST_CASE("NOT-Hidden This time", 5.0);  // A 40-point hidden test case.

  CHECK(SquareRoot(4.0) == 2.0);
  CHECK(SquareRoot(16.0) == 4.0);
  CHECK(SquareRoot(1000000.0) == 1000.0, "Fails when tested on large values.");
  CHECK(SquareRoot(0.0) == 0.0, "Fails when tested on ZERO.");

}
