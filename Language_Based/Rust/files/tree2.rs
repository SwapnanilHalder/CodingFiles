use std::io;
use std::collections::HashMap;
// use std::process::Command;

fn main() {
    // Command::new("clear").status().expect("process failed to execute");
    // let mut list_dir = Command::new("clear");
    // list_dir.status().expect("process failed to execute");
    let t = read_to_i32();
    for _ in 0..t {
        let _size = read_to_i32();
        let vec = read_to_vector();
        
        let mut hash_map = HashMap::new();
        let mut count:i32 = 0;
        for &m in vec.iter() {
            if !hash_map.contains_key(&m) {
                hash_map.insert(m, 1);
                count += 1;
            }
            else {
                // hash_map.entry(m).and_modify(|e| {*e += 1}).or_insert(42);
                let temp = hash_map.entry(m).or_insert(0);
                *temp +=1;
            }
        }
        // _do_it(&mut hash_map);

        println!("{}", count);
    }
}

fn _do_it(map: &mut HashMap<i32, i32>) {
    for (key, value) in &*map {
        println!("{} / {}", key, value);
    }
    map.clear();
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