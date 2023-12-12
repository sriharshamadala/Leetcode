impl Solution {
    
    pub fn permute_recursive(nums: &[i32]) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        
        if nums.len() == 1 {
            result.push(nums.to_vec());
            return result;
        } else {
            let sub_result = Self::permute_recursive(&nums[1..]);
            
            for set in sub_result {
                for index in 0..set.len()+1 {
                    let mut temp_set = set.clone();
                    temp_set.insert(index, nums[0]);
                    result.push(temp_set);
                }
            }
            
            return result;
        }
    }
    
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        Self::permute_recursive(&nums[..])
    }
}