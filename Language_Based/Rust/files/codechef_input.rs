use std::io;

fn main() {
    let t = read_to_i32();
    let str = read_to_string();
    let vector = read_to_vector();
    println!("Vector : {:?}", vector);
    println!("The number : {}", t);
    println!("The string : {}", str);
}

fn read_to_i32() ->i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let res = input.trim().parse::<i32>().unwrap();
    return res;
}

fn read_to_vector() -> Vec<i32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let vec: Vec<i32> = input
                        .split_whitespace()
                        .map(|s| s.parse::<i32>().unwrap())
                        .collect();
    vec   
}

fn read_to_string() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

