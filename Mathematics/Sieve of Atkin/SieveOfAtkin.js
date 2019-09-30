// In mathematics, the sieve of Atkin is a modern algorithm for finding all prime numbers up to a specified integer.

const sieveOfAtkin = (limit = 0) => {
  let primes = [2, 3];
  let sieve = new Array(limit);
  for (let x = 1, xSquared = x * x; xSquared < limit; x++) {
    xSquared = x * x;
    for (let y = 1, ySquared = y * y; ySquared < limit; y++) {
      ySquared = y * y;
      let n = 4 * xSquared + ySquared;
      if (n <= limit) {
        let mod12Check = n % 12;
        if (mod12Check === 1 || mod12Check === 5) sieve[n] = !sieve[n];
      }
      let threeXSquared = 3 * xSquared;
      n = threeXSquared + ySquared;
      if (n <= limit && n % 12 === 7) sieve[n] = !sieve[n];
      n = threeXSquared - ySquared;
      if (x > y && n <= limit && n % 12 === 11) sieve[n] = !sieve[n];
    }
  }
  for (let r = 5; r * r < limit; r++)
    if (sieve[r]) for (let i = r * r; i < limit; i += r * r) sieve[i] = false;
  for (let a = 5; a < limit; a++) if (sieve[a]) primes.push(a);
  return limit < 2 ? [] : limit === 2 ? [2] : limit === 3 ? [2, 3] : primes;
};

export default sieveOfAtkin;
