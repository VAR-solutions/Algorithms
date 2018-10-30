/**
 * Long Method
 */
// const reverseString = (str) => {
//     let newStr = "";
//     for(let i=str.length-1; i>=0; i--){
//       newStr=newStr+str[i];
//     }
//     console.log(newStr);
//     console.log(str);
// }

/**
 * Using Recursion
 */
// function reverseString(str){
//     if(str === "")
//         return "";
//     else {
//         return reverseString(str.substr(1)) + str.charAt(0);
//     }
// }

/**
 * Shortcut Method
 */
function reverseString(str){
    if(str === "")
        return "";
    else {
        return str.split("").reverse().join("");
    }
}

console.log(reverseString("hello"));
console.log(reverseString("apple"));
