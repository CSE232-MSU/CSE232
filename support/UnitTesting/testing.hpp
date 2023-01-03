/**
 *  @copyright Copyright (C) Michigan State University, MIT Software license
 *  @date 2023.
 *
 *  @file testing.hpp
 *  @brief A simple C++ unit-test managing system for CSE 232 at Michigan State University
 **/

#ifndef CSE232_UNIT_TESTING
#define CSE232_UNIT_TESTING

#include <string>
#include <vector>

namespace cse232 {

  // Helper functions.
  template <typename... Ts>
  size_t find_any_of(
    const std::string test_str,
    size_t start_pos,
    std::string test1,
    Ts... tests)
  {
    size_t pos1 = test_str.find(test1, start_pos);
    if constexpr (sizeof...(Ts) == 0) return pos1;
    else {
      size_t pos2 = find_any_of(test_str, start_pos, tests...);
      if (pos1 == std::string::npos) return pos2;
      if (pos2 == std::string::npos) return pos1;
      return std::min(pos1, pos2);
    }
  }
  
  /// Manage a set of unit tests.
  struct UnitTester {
    size_t check_count = 0;

    struct CheckInfo {
      std::string lhs = "";
      std::string rhs = "";
      std::string comparator = "";
      bool passed = false;
      std::string message = "";  // Message on failure.
    };

    struct CaseInfo {
      std::string name;
      double points = 0.0;
      size_t checks_passed = 0;
      size_t checks_failed = 0;
      bool hidden = false;

      std::vector<CheckInfo> checks;
    };

    std::vector<CaseInfo> test_cases;

    // Track the two sides of a comparison (if only one side, rhs will be "")
    std::string lhs = "";
    std::string rhs = "";
    
    void IncCheckNumber() {
      check_count++;
    }

    CaseInfo & AddTestCase(const std::string & name, double points) {
      test_cases.push_back(CaseInfo{name, points});
      return test_cases.back();
    }

    /// Scan the check that's about to happen to make sure the test is legal and
    /// to store the two sides.
    void SetupCheck(const std::string & test, size_t line_num, const std::string & filename) {
      // For the moment we are allowing only a single comparison and no && or ||
      if (find_any_of(test, 0, "&&", "||") != std::string::npos) {
        std::cerr << "Internal error (line " << line_num << " of " << filename
		              << "): Unit test checks do not allow \"&&\" or \"||\"." << std::endl;
	      exit(1);
      }

      // Make sure there is a single comparator.
      auto comp_pos = find_any_of(test, 0, "==", "!=", "<", "<=", ">", ">=");

      // Make sure we don't have a second comparator.
      if (comp_pos != std::string::npos &&
          find_any_of(test, comp_pos+2, "==", "!=", "<", "<=", ">", ">=") != std::string::npos) {
        std::cerr << "Internal error (line " << line_num << " of " << filename
	                << "): Unit test checks cannot have more than one comparison." << std::endl;
        exit(1);
      }

      // Determine which comparison operator we are working with (if any) and the terms being compared.
      CheckInfo check_info;
      if (comp_pos != std::string::npos) {
        check_info.comparator += test[comp_pos];
        if (test[comp_pos+1] == '=') check_info.comparator += "=";

        // Identify the left and right hand sides
        check_info.lhs = test.substr(0,comp_pos);
        check_info.rhs = test.substr(comp_pos+comparator.size());
      }
      else {
        check_info.lhs = test;
      }

      // Make sure we have a test case to include this check in.
      if (test_cases.size() == 0) {
        std::cerr << "Added test case `DEFAULT`" << std::endl;
        test_cases.push_back(CaseInfo{"DEFAULT"});
      }

      // Insert this check's information into the current test case.
      test_cases.back().checks.push_back(check_info);
    }

  };

  /// Create a singleton unit tester.
  static UnitTester & GetUnitTester() {
    static UnitTester ut;
    return ut;
  }
  
}


/// Start a new test case with the given number of points.
#define TEST_CASE(NAME, POINTS) {                    \
    auto & unit_tester = cse232::GetUnitTester();    \
    unit_tester.AddTestCase(NAME, POINTS);           \
  }

/// Start a new test case with the given number of points.
#define HIDDEN_TEST_CASE(NAME, POINTS) {                 \
    auto & unit_tester = cse232::GetUnitTester();	       \
    unit_tester.AddTestCase(NAME, POINTS).hidden = true; \
  }

/// A single CHECK within a unit test.  If additional arguments are included
/// they are printed when if test fails.
#define CHECK(TEST, ...) {		                          \
    auto & unit_tester = cse232::GetUnitTester();       \
    unit_tester.SetupCheck(#TEST, __LINE__, __FILE__);  \
    unit_tester << TEST;                                \
  }


#endif
