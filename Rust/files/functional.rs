use std::io;

fn main() {
    let xs = vec!["lorem", "ipsum", "dolor", "hello", "hmmm", "hiii", "swap", "swim"];
    let v = xs.into_iter()
            .filter(|item| item.ends_with('m') )
            .take(5)
            .collect::<Vec<_>>();
    
    //xs.iter().filter(|item| item.ends_with('m'));
    // println!("{:?}", v.next());
    // println!("{:?}", v.next());
    // println!("{:?}", v.next());
    // println!("{:?}", v.next());
    // println!("{:?}", v.next());
    println!("{:?}", v);
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

