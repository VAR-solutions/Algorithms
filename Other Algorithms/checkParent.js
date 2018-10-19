// Una funcion que devuelve true/false si tiene la misma cantidad de "(" y de ")"

function checkParent (str) {

var result = str.split("").reduce(function (previus,char) {
    if (char === "(" ) { return ++previus; }
    if (char === ")" ) { return --previus; }
   return previus;
},0);
   return !Boolean(result);
}


console.log(checkParent("(((())"));
