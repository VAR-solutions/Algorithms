#include "binary_search.h"
#include "catch.hpp"

SCENARIO("Testing binary_search", "[binary_search][unit]") {
  GIVEN("Sorted integer array with 5 elements") {
    int arr[5] = {1, 2, 3, 4, 5};

    WHEN("binary_search called with given array and elementToFind as 1(first "
         "element)") {
      int elementToFind = 1;
      int actualIndex = binary_search(arr, 5, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = 0;
        REQUIRE(actualIndex == expectedIndex);
      }
    }

    WHEN("binary_search called with given array and elementToFind as 4") {
      int elementToFind = 3;
      int actualIndex = binary_search(arr, 5, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = 2;
        REQUIRE(actualIndex == expectedIndex);
      }
    }

    WHEN("binary_search called with given array and elementToFind as 12 which "
         "is not exists in given array") {
      int elementToFind = 12;
      int actualIndex = binary_search(arr, 5, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = -1;
        REQUIRE(actualIndex == expectedIndex);
      }
    }
  }
  GIVEN("Sorted integer array with 15 elements") {

    int arr[15] = {17, 32, 44, 47, 50, 51, 52, 67, 69, 71, 77, 81, 88, 92, 100};

    WHEN("binary_search called with given array and elementToFind as 44") {
      int elementToFind = 44;
      int actualIndex = binary_search(arr, 15, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = 2;
        REQUIRE(actualIndex == expectedIndex);
      }
    }

    WHEN("binary_search called with given array and elementToFind as 67(middle "
         "element)") {
      int elementToFind = 67;
      int actualIndex = binary_search(arr, 15, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = 7;
        REQUIRE(actualIndex == expectedIndex);
      }
    }

    WHEN("binary_search called with given array and elementToFind as 17(first "
         "element)") {
      int elementToFind = 17;
      int actualIndex = binary_search(arr, 15, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = 0;
        REQUIRE(actualIndex == expectedIndex);
      }
    }

    WHEN("binary_search called with given array and elementToFind as 100(last "
         "element)") {
      int elementToFind = 100;
      int actualIndex = binary_search(arr, 15, elementToFind);
      THEN("actualIndex should equal to expectedIndex") {
        int expectedIndex = 14;
        REQUIRE(actualIndex == expectedIndex);
      }
    }
  }
}
