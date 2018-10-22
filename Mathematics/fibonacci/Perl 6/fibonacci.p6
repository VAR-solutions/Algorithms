sub fibonacci($n) {
  if ($n < 3) { return 1; }
  else {
    return fibonacci($n - 1) + fibonacci($n - 2);
  }
}

sub MAIN($i) {
  say fibonacci($i);
}
