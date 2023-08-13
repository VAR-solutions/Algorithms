import 'dart:math' show Random;

main() {
  for (var i = 0; i < 10; i++) {
    // prints 0, 1, or 2
    print(new Random().nextInt(3));
  }
}