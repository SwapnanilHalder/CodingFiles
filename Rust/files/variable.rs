use std::fs::File;
use std::io::prelude::*;

enum Direction {
    Up, _Down, _Left, _Right,
}

struct Color {
    red: u8, green: u8, blue: u8,
}

struct Rect {
    width:u32, height: u32,
}

impl Rect {
    fn print_desc(&self) {
        println!("Rectangle : {} X {}", self.height, self.width);
    }
    fn is_square(&self) -> bool {
        return self.height == self.width;
    }
}

// Tuple Struct
struct Colour(u8, u8, u8);

const PI:f32 = 3.14;
fn main() {
    let mut x = 45;
    println!("The value of x is {}", x);

    x = 60;
    println!("The value of x is {}", x);
    let f: i128= 666666666666666666;
    println!("{}", f);


    if x < 30 {
        println!("The number is less than 90");
    }
    else if x == 60 {
        println!("The number is 60");
    }

    loop {
        x += 1;
        if x > 90 {
            break;
        }
        if x == 70 {
            continue;
        }
        println!("Number :  {}", x);
    }
    while x <= 200 {
        if x%5 == 0 {
            println!("x is : {}", x);
        }
        x += 1;
    }
    let numbers = 30..41;
    for i in numbers {
        println!("i : {}", i);
    }

    let animals = vec!["Rabbit", "Dog", "Cat"];
    for (index, value) in animals.iter().enumerate() {
        println!("{}th animal name : {}",index+1, value);
    }

    let player_dir:Direction = Direction::Up;
    match player_dir {
        Direction::Up => println!("We are heading up!"),
        Direction::_Down => println!("We are heading down!"),
        Direction::_Left => println!("We are heading left!"),
        Direction::_Right => println!("We are heading right!"),
    }
    println!("Pi is : {}", PI);

    let tuple = (20, "Rust", 3.44, false, (5,4,2));
    println!("{} , value : {}", tuple.1, (tuple.4).2);
    
    x = 200;
    println!("The number {} is even : {}", x, is_even(x));

    let mut p = 20;
    {
        let dom = &mut p;
        *dom += 1;
        println!("Reference of p is : {}", dom);
    }
    println!("p is {}", p);

    let mut bg = Color{red: 255, green: 70, blue: 15};
    bg.blue = 45;
    println!("red: {}, green: {}, blue: {}", bg.red, bg.green, bg.blue);

    let red = Colour(255, 0, 0);
    print_color(&red);


    // Array
    let arr = [1,2,3,4,5,98,43];
    for i in 0..arr.len() {
        print!("{}  ", arr[i]);
    }println!();


    // Impl
    let my_rect = Rect{height: 5, width: 10};
    my_rect.print_desc();

    let my_sq = Rect{width:10, height: 10};
    println!("my_sq is square : {}", my_sq.is_square());

    let my_str = String::from("How's it going today?");
    println!("Str : {}", my_str);


    // Read from file
    let mut file = File::open("info.txt").expect("Can't open file!!");
    let mut contents = String::new();
    file.read_to_string(&mut contents).expect("Can't read file");
    println!("File contents are: \n\n{}", contents);
} 

fn is_even(num:i64) -> bool {
    return num%2 == 0;
}

fn print_color(c: &Colour) {
    println!("red is {} {} {}", c.0, c.1, c.2);
}
