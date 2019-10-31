//La función genera un número aleatorio entre 1 y el número deseado

function numRandom (start, end) {
 return Math.floor((Math.random() * (end - start)) + start); 
}

console.log(numRandom(1,5));
