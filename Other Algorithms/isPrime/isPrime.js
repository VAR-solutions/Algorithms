
// La función booleana devuelve true/false en dependencia de si el número pasado es o no primo

  function isPrime(number){

      for (i = 2; i <= number; i++){
          if(number % i === 0 && number!= i){
             return false;
          }
       }
      return true;
  }

console.log(isPrime(9));
