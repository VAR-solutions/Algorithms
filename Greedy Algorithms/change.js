function computeChange(coins, amount) {
    // Create a array that is used to return the final result, instead of the global one.
    var coincount = [];

    // use the given `amount` to set `creminder ` rather than `AMOUNT` which may not be accessible if your code is called otherplace rather than here.
    var i = 0; var creminder = amount; var ccoin;


    while( i < coins.length )
    {
      // Lazily init the used coin for coin type i to 0.
      coincount[i] = 0;
      while ( coins[i] <= creminder )
      {
        creminder = creminder - coins[i];
        ccoin = coincount[i];
        ccoin += 1;
        coincount[i] = ccoin;
      }

      i++;
    }

    return coincount;
}
