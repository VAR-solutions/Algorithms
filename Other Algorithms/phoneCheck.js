
// Valida si el numero de telefono es validdo para EU

function phoneCheck(str) {
  
  var exp = /^(1\s?)?(\(\d{3}\)|\d{3})[\s\-]?\d{3}[\s\-]?\d{4}$/;
  return exp.test(str);
}

console.log(phoneCheck("555-555-5555"));
