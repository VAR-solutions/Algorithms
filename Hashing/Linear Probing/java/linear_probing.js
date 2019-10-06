function linearProbing(size, array, hash = 11, hash_function = 'mod', tiebraker_function = 'mod', tiebraker_hash = 11) {
  var access = 0;
  var reorder = new Array(size);
  var c = [];

  array.forEach(function(i) {
    for (count = 0, f = h(hash_function, hash, i);;) {
      if (isNaN(f)) {
        break;
      }
      if (!reorder[f]) {
        access = access + (count + 1);
        reorder[f] = i, count = 0; break;
      }
      count = count + 1;
      s = h(hash_function, hash, i) + count;

      f = h(tiebraker_function, tiebraker_hash, s);
    }
  });

  for (j = 0; j < size; j++) {
    c.push(reorder[j] || null);
  }
  return {
    hits: access/array.length,
    result: c
  }
}

function h(f, y, x) {
  y = parseInt(y);
  x = parseInt(x);

  if (f == "mod") return x % y;
  else if (f == "floor") return Math.floor(x / y);
  else if (f == "round") return Math.round(x / y);
  else {
    a = new Function("x", "return " + f);
    return Math.round(a(x));
  }
}
