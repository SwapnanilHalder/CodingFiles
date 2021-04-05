use std::process::Command;

fn main() {
    let mut list_dir = Command::new("clear");
    list_dir.status().expect("process failed to execute");
}