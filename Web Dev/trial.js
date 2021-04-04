let array = [1,2,10,16];
let newArray = [];
array.forEach((value, index, array) => {
    newArray.push(value * 2);
})

console.log('forEach : ', newArray);

const mapArray = array.map((value) => value * 3);
const filterArray = array.filter((value) => (value > 5));

console.log('map : ', mapArray);
console.log('filter : ', filterArray);