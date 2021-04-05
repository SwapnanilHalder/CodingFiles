use std::time::{Instant};

fn main() {
    let start = Instant::now();
    let x = String::from("Hiii");
    println!("{}", x);
    let duration = start.elapsed();
    println!("Time elapsed in the fn.: {:?}",duration);
}