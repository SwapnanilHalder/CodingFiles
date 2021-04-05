fn main() {
    let y = String::from("Hey Hey Hey");
    println!("{}", y);
    let mut x = y.clone();
    drop_str(&mut x);
    println!("str : {}", x);
}

fn drop_str(s:&mut String) {
    s.clear();
}