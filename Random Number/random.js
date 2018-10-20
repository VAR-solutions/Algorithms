//La función genera un número aleatorio entre 1 y el número deseado

function numRandom (num) {

 return Math.floor((Math.random() * num) + 1); 

}

console.log(numRandom(5));
