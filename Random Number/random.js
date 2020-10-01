//La función genera un número aleatorio entre 1 y el número deseado
var number=5;
var A = [];
function getRandomInt(min,max){
	return Math.floor(Math.random() * (max - min + 1)) + min;
}

for (i = 0; i < number; i++){
  A[i] = getRandomInt(1,30);
  console.log(A[i]);
}


