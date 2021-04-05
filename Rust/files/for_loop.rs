fn main() {
    for i in (2..).take_while(|i| i*i < 109) {
        println!("The number : {}", i);
    }
}