// Fiil array with 10 random values between 0-100 to calculate harmonic mean
values = [];
number_of_values = 10;
max_value = 100;
for (var i = 0; i < number_of_values; i++) {
  values.push(Math.round(Math.random() * max_value));
}

var sum = values.reduce((a, b) => 1/a + 1/b, 0);
var harmonic_mean = number_of_values/sum;

console.log(harmonic_mean);
