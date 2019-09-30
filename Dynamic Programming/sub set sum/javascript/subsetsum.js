function ArrayAddition(arr) { 
  var mp = {
      0: 1
  };
  
  arr = arr.sort(function(a, b){return a-b});
  var mx = arr[arr.length - 1];
  
  for (var i = 0; i < arr.length - 1; i++) {
      var keys = Object.keys(mp);
      //console.log(keys, arr[i]);
      for (var j = 0; j < keys.length; j++) {
          var next = parseInt(keys[j]) + arr[i];
          if (next == mx) {
              return true;
          } else if(next < mx && next > (0 - (arr.length - i - 1) * mx)) {
              mp[next] = 1;
          }
          
      }
  }

  return false;         
} 
