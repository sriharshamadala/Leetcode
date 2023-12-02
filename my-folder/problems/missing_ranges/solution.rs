impl Solution {
    pub fn find_missing_ranges(nums: Vec<i32>, lower: i32, upper: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let nums_len = nums.len();

        if nums_len == 0 {
            result.push(vec![lower, upper]);
            return result;
        }

        if nums[0] > lower {
            result.push(vec![lower, nums[0]-1]);
        }

        for (index, num) in nums.iter().enumerate().skip(1) {
            let prev_num = nums[index - 1];
            if *num > prev_num + 1 {
                result.push(vec![prev_num + 1, *num - 1]);
            }
        }

        if nums[nums_len - 1] < upper {
            result.push(vec![nums[nums_len - 1]+1, upper]);
        }

        result
    }
}