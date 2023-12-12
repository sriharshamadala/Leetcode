use std::collections::HashSet;

impl Solution {    
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut num1_collection = HashSet::new();
        let mut num2_collection = HashSet::new();
        let mut result = Vec::new();
        
        for num in nums1 {
            num1_collection.insert(num);
        }
        
        for num in nums2 {
            num2_collection.insert(num);
        }
        
        for num in num2_collection {
            if let Some(_) = num1_collection.get(&num) {
                result.push(num);        
            }
        }
        
        result
    }
}