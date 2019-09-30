var size_of_sequence = 10;
var a, b;
a = b = 1;
sequence = [];
sequence.push(a);
sequence.push(b);
total_in_sequense = 2;

for (var i = 2; total_in_sequense < size_of_sequence; i++) {
  if (a + b == i) {
    a = b;
    b = i;
    sequence.push(i);
    total_in_sequense++;
  }
}
console.log(sequence.join(", "));
