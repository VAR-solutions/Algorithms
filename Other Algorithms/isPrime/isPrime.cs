public static bool isPrime(int num) {
	for (int i = 2; i <= num; i++) {
      if((num%i) == 0 && num != i) {
        return false;
      }
  }	
  return true;
}
