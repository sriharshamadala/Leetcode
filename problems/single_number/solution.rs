impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        /*
        let mut single_number: i32 = 0;

        for num in nums {
            single_number = single_number ^ num;
        }

        single_number
        */

        nums.into_iter().fold(0, |acc, curr| acc ^ curr)
    }
}