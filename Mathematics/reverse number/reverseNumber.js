function revInt(num) {
    var rem, rev=0;
    while(num > 0){
        rem = num % 10;
        rev = rev*10 + rem;
        num = parseInt(num/10);
    }
    console.log(rev);
}

// Commented Out ShortCut method
// const revInt = (n) => {
//   let rev = n.toString().split('').reverse().join("");
//   console.log(Number(rev));
// }

revInt(15);