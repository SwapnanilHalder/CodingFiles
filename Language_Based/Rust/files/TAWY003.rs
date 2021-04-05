#![allow(non_snake_case)]

use std::io;

fn main() {
    let _t = _read_to_i32();
    sol();
}

fn sol() {
    let mut arr = _read_to_vector();
    arr.sort_unstable();
    let mut sum = 0;
    let mut count = 6;
    for num in arr.iter() {
        sum += num;
        if sum <= 500 {
            count += 1;
        }
        else {
            break;
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

