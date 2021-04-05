#![allow(unused_assignments)]
fn main() {
    let mut array = vec![7,1,5,3,6,4];
    let num = max_profit(&mut array);
    println!("Array : {:?}", array);
    println!("Return Value : {}" , num);
}

pub fn max_profit(prices:&mut Vec<i32>) -> i32 {
    let mut profit = 0;
    let mut buy = 0;
    let mut sell = 0;
    if prices.len() == 0 {return 0;}
    buy = prices[0]; sell = prices[0];
    for i in 1..prices.len() {
        if prices[i] > sell {
            sell = prices[i];
        }
        if prices[i] < sell || i == prices.len()-1 {
            profit += sell - buy;
            buy = prices[i]; sell = prices[i];
        }
    }
    return profit;
}

