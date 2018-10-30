const sieveOfAtkin = require("./SieveOfAtkin.js");

test("Should return correct prime numbers in an array", () => {
  expect(sieveOfAtkin(35)).toBe([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]);
});
