let arr = [1,2,10,3,2,4,3,3,4,5,6,7,8,9,8];
let set = new Set(arr);
let unique = [];
set.forEach((i)=> unique.push(i))
console.log(unique);