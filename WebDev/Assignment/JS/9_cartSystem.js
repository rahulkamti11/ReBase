let cart = [];

let addItem = (name , price , quantity) => {

    let item = {
    name: name,
    price: price , 
    quantity: quantity
    }

    return item;
}

cart.push(addItem("Apple" , 20 , 10));
cart.push(addItem("Pens" , 10 , 10));
cart.push(addItem("Mobile" , 10000 , 1));
cart.push(addItem("Laptop" , 50000 , 1));

console.log(cart);

