use std::io;

fn main() {
    let mut input = String::new();
    println!("hey mate! Say something!");

    // match io::stdin().read_line(&mut input) {
    //     Ok(_) => {
    //         println!("Success! You said : {}", input);
    //     }
    //     Err(e) => println!("Oops! Something went wrong: {}", e)
    // } 

    io::stdin().read_line(&mut input).expect("Operation Failed");
    let input = input.trim();
    let mut x = input.parse::<f64>().expect("__");
    println!("The number : {}", x);
    x = 666999.564;
    println!("Now : {}", x);
}