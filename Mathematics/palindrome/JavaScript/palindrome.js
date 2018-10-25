function palindrome(str) {
    str = str.toLowerCase();
    str = str.replace(/[\s_,.()|:-]/g, "");
    
    let newStr = str.split("").reverse().join("");
    if(newStr === str){
        output = true;
    }
    else{
        output = false;
    }
    console.log(output);
}

palindrome("eye");
palindrome("_eye");
palindrome("race car");
palindrome("not a palindrome");
palindrome("A man, a plan, a canal. Panama");
palindrome("never odd or even");
palindrome("nope");
palindrome("almostomla");
palindrome("My age is 0, 0 si ega ym.");
palindrome("1 eye for of 1 eye.")
palindrome("0_0 (: /-\ :) 0-0");
palindrome("five|\_/|four");