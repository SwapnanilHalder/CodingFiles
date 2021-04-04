class player {
    constructor (name, type) {
        console.log(this);
        this.name = name;
        this.type = type;
    }

    introduce() {
        console.log(`Hi, I am a player of name : ${this.name} and, my type is : ${this.type}`);
    }
}

class wizard extends player {
    constructor(name, type) {
        super (name, type);
        console.log(this);
    }

    play() {
        console.log(`Wee, I'm am a ${this.type}`);
    }
}

const wizard1 = new wizard('Shelly', 'Healer');
const wizard2 = new wizard('Shawn', 'Dark Magic');

let obj = {
    a: 'a',
    b: 'b',
    c: {
        deep: 'Try to change me',
    }
}
let assignClone = Object.assign({}, obj);
let shallowClone = {...obj};
let deepClone = JSON.parse(JSON.stringify(obj));

obj.b = 'B',
obj.c.deep = 'CHANGED'

console.log('Assign : ', assignClone);
console.log('Shallow : ', shallowClone);
console.log('Deep JSON clone : ', deepClone);