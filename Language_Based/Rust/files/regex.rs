use regex::Regex;

fn main() {
    let re = Regex::new(r"(\w{5})").unwrap();
    let text = "dcode";

    match re.captures(text) {
        Some(caps) => println!("Found match: {}", caps.get(1).unwrap().as_str()),
        None => println!("Couldn't find match"),
    }
}