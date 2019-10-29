Truncate a String
(taken from FreeCodeCamp - Basic Algorithms)

Instructions

- Truncate a stirng (first argument) if it is longer than the given maximum string length (second argument). Return the trucated string with a ... ending.

Test Scenarios

- truncateString("A-tisket a-tasket A green and yellow basket", 8) should return "A-tisket...".
- truncateString("Peter Piper picked a peck of pickled peppers", 11) should return "Peter Piper...".
- truncateString("A-tisket a-tasket A green and yellow basket", "A-tisket a-tasket A green and yellow basket".length) should return "A-tisket a-tasket A green and yellow basket".
- truncateString("A-tisket a-tasket A green and yellow basket", "A-tisket a-tasket A green and yellow basket".length + 2) should return "A-tisket a-tasket A green and yellow basket".
- truncateString("A-", 1) should return "A...".
- truncateString("Absolutely Longer", 2) should return "Ab...".
