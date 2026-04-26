let string = "HelloMyNameIsRrahul".toLowerCase();
let set = new Set(string);
let count = 0;
let array = [];


set.forEach((ch) => {
    for (let i = 0; i < string.length; i++) {
        if (ch == string[i]){
            count++;
        }
    }
    array.push(count);
    count =0;
})

let chars = []; 
set.forEach((ch) => chars.push(ch));


for(let i=0 ; i<set.size ; i++){
    console.log(chars[i] + " : " + array[i]);
}

