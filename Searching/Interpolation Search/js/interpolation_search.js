function interpolation(array, match) {
  var c = [], mid, i = 0 , f = array.length - 1;

  while (match > array[i] && match <= array[f]) {
    c.push({
      "i": i,
      "f": f,
      "comparison": match + " > " + array[i] + " && " + match + " <= " + array[f] + "?"
    });

    mid = Math.floor(i + ((match - array[i])/(array[f] - array[i])) * (f - i));

    if (match > array[mid]) {
      i = mid + 1;
    } else if (match < array[mid]) {
      f = mid - 1;
    } else {
      i = mid
    }
  }
  c.push({
    "i": i,
    "f": f,
    "comparison": match + " > " + array[i] + " && " + match + " <= " + array[f] + "?"
  });

  return {
    comparisons: c,
    result: (array[i] == match)? i: -1
  };
}
