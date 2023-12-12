impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        // Calculate sum and find the missing number
        let n = nums.len() as i32;
        let sum = (n * (n + 1)) / 2;
        sum - nums.into_iter().fold(0, |acc, num| acc + num)
    }
}