let array = [1,3,4,5,8,6,2,3,1]; //Assuming all no. are positive
let largest = -1;

for(let val of array){
    if(val > largest) largest = val;
}
    
console.log("Largest No.: " + largest);
