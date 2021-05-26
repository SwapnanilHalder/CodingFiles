#![allow(unused_assignments)]
#![allow(non_snake_case)]
use std::io;

fn main() {
    let vector = _read_to_vector();
    let mut count = 0;
    for _ in 0..vector[0] {
        let x = _read_to_i32();
        if x % vector[1] == 0 {
            count += 1;
        }
    }
    println!("{}", count);
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

