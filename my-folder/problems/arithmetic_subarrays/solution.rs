impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let mut result = Vec::new();

        for mth_query in 0..l.len() {
            let left_index = l[mth_query] as usize;
            let right_index = r[mth_query] as usize;
            
            let length_of_subarray = right_index - left_index + 1;
            let mut sub_array = vec![0; length_of_subarray];
            
            sub_array.clone_from_slice(&nums[left_index..=right_index]);
            sub_array.sort();
            result.push(Solution::check_arithmetic_sorted_array(&sub_array));
        }

        result
    }

    pub fn check_arithmetic_sorted_array(nums: &Vec<i32>) -> bool {
        let mut delta = 0;
        if nums.len() <= 2 {
            return true;
        }
        else {
            delta = nums[1] - nums[0];
        }

        for index in 1..nums.len()-1 {
            let curr_delta = nums[index+1] - nums[index];
            if curr_delta != delta {
                return false;
            }
        }

        return true;
    }
}