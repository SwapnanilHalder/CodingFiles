#![allow(non_snake_case)]
#![allow(unused_variables)]
use std::io;

fn main() {
    let s = 42;
    loop {
        let t = _read_to_i32();
        if t == 42{
            break;
        }
        else {
            println!("{}", t);
        }
    }
}

fn _read_to_i32() ->i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let res = input.trim().parse::<i32>().unwrap();
    return res;
}

fn _read_to_vector() -> Vec<i32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let vec: Vec<i32> = input
                        .split_whitespace()
                        .map(|s| s.parse::<i32>().unwrap())
                        .collect();
    vec   
}

fn _read_to_string() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

