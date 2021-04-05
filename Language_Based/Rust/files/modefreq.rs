use std::io;
use std::collections::HashMap;

fn sol() {
    let _n = read_to_i32();
    let v = read_to_vector();
    let mut hash_map: HashMap<i32, i32> = HashMap::new();
    for m in v.iter() {
        *hash_map.entry(*m).or_insert(0) += 1;
        // if !hash_map.contains_key(m) {
        //     hash_map.insert(*m, 1);
        // } else {
        //     let temp = hash_map.entry(*m).or_insert(0);
        //     *temp +=1;
        // }
    }
    let mut count_map: HashMap<i32, i32> = HashMap::new();
    for (_, val) in hash_map.iter() {
        *count_map.entry(*val).or_insert(0) += 1;
    }
    println!("{:?}", hash_map);
    println!("{:?}", count_map);

}
fn main() {
    let t = read_to_i32();
    for _ in 0..t {
        sol();
    }
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

fn _read_to_string() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}