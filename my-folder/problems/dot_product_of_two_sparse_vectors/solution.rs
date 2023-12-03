use std::collections::HashMap;

struct SparseVector {
	data: HashMap<usize, i32>
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SparseVector {
    fn new(nums: Vec<i32>) -> Self {
        SparseVector {
            data: nums.into_iter().enumerate().filter(|(index, num)| *num != 0).collect()
        }
    }
	
    // Return the dotProduct of two sparse vectors
    fn dot_product(&self, vec: SparseVector) -> i32 {
        self.data.iter().fold(0, |acc, (index, num)| acc + num * vec.data.get(index).unwrap_or(&0))
    }
}

/**
 * Your SparseVector object will be instantiated and called as such:
 * let v1 = SparseVector::new(nums1);
 * let v2 = SparseVector::new(nums2);
 * let ans = v1.dot_product(v2);
 */