 
#![allow(unused_assignments)]
#![allow(non_snake_case)]
use std::io;

fn main() {
    sol();
}

fn sol() {
    let n = _read_to_i32();
    let arr = _read_to_vector();
    let mut dp = arr.clone();
    for _ in 0..n-1 {
        let arr = _read_to_vector();
        let mut new_dp = vec![0;3];
        for j in 0..3 {
            new_dp[j] = arr[j] + std::cmp::max(dp[(j+1) %3], dp[(j+2)%3]);
        }
        dp = new_dp;
    }
    println!("{}", dp.iter().max().unwrap());
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

