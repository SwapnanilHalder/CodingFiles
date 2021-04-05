use std::io;
use std::io::{BufRead, Write};

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    input(stdin.lock(), stdout.lock());
}

fn input<R: BufRead, W: Write>(mut input: R, mut _output: W){
    let mut buf = String::new();
    input.read_line(&mut buf).unwrap();

}