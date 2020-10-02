#include <iostream>
#include <string>
#include <vector>
using namespace std;

string digitName(int digit);
string teenName(int number);
string tensName(int number);
string intName(int number);

vector<string> ones{ "",     "one", "two",   "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> teens{"ten",     "eleven",  "twelve",    "thirteen", "fourteen","fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
vector<string> tens{ "",      "",      "twenty",  "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string
nameForNumber(long number)
{
  if (number < 10) {
    return ones[number];
  } else if (number < 20) {
    return teens[number - 10];
  } else if (number < 100) {
    return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
  } else if (number < 1000) {
    return nameForNumber(number / 100) + " hundred" +
           ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
  } else if (number < 1000000) {
    return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
  } else if (number < 1000000000) {
    return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
  } else if (number < 1000000000000) {
    return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
  } else
    return "error";
}

int
main()
{
  long input;
  do {
    cout << "Please enter a integer (Press a 0 to exit): ";
    cin >> input;
    if (input < 0) {
      input *= -1;
      cout << "\nnegative " << nameForNumber(input) << endl;
    } else {
      cout << "\n" << nameForNumber(input) << endl;
    }
  } while (input);
  return 0;
}
