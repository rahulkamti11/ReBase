let temp , array = [3,5,6,2,6,1,8,6];

for(let i=0 ; i<array.length ; i++){
    for(let j=0 ; j<array.length-1-i ; j++){
        if(array[j]>array[j+1]){
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        } 
    }
}

console.log(array)