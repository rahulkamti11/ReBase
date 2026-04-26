let palindrome = (string)=>{
    let len = string.length;
    for(let i = 0 ; i<len/2 ; i++){
        if(string[i] == string[len-1-i]){}
        else return "Not Palindrome"
    }
    return "Palindrome";
}

console.log("rahul  : " + palindrome("rahul"));   // Odd Length
console.log("nitin  : " + palindrome("nitin"));   // Odd Length
console.log("Rahull : " + palindrome("rahull"));  // Even Length
console.log("Nittin : " + palindrome("nittin"));  // Even Length
