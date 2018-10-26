/**
 * An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.
 * For instance, a 3 digit number will be considered an Armstrong number if the sum of the cubes of its digits is equal to the number itself. 
 * For example, 153 is an Armstrong number, as 1**3 + 5**3 + 3**3 = 153
 */

const armstrongNumber = (num) => {
    let sum = 0;
    let ar = num.toString().split("");
    for(let i = 0; i<ar.length; i++){
        sum = sum + Math.pow(Number(ar[i]), ar.length);
    }

    if(sum === num){
        console.log( "Armstrong Number");
    }
    else{
        console.log("Not an Armstrong Number");
    }
}

armstrongNumber(144);
armstrongNumber(153);
