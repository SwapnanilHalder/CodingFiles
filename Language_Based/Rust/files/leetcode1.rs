
fn main() {
    let mut nums = vec![0,0,1,1,1,2,2,3,3,4];
    let num = remove_duplicates(&mut nums);
    println!("num : {}", num);
}

pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    let mut count = 0;
    let mut i = 1;
    let length:i32 = nums.len() as i32;
    while i < nums.len() {
        println!("{}", nums[i]);
        if nums[i] == nums[i-1] {
            println!("no. : {}", nums[i]);
            nums.remove(i); 
            count += 1;  
        }
        else {
            i += 1;
        }
    //    println!("{}", nums[i]);
    }
    println!("{:?}", nums);
    return length-count;
}


