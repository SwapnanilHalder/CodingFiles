#![allow(unused_assignments)]
#![allow(non_snake_case)]
use std::io;

fn main() {
    let t = _read_to_i32();
    for _ in 0..t {
        solve();
    }
}

fn solve() {
    let n = _read_to_i32();
    let mut arr = _read_to_vector();
    // let mut vec1: Vec<i32> = Vec::new();
    // let mut vec2: Vec<i32> = Vec::new();
    arr.sort_unstable();
    let mut sum1:i32 = arr[(n-2) as usize];
    let mut sum2:i32 = arr[(n-1) as usize];
    let mut diff = sum1-sum2;
    for i in (0..n-2).rev() {
        if diff > 0 {
            sum2 += arr[i as usize];
        } 
        else {
            sum1 += arr[i as usize];
        }
        diff = sum1 - sum2;
    }
    println!("{}", std::cmp::max(sum1, sum2));
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

