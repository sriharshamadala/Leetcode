impl Solution {
    pub fn hammingWeight (mut n: u32) -> i32 {
        let mut hamming_weight: i32 = 0;

        while n > 0 {
            hamming_weight += (n & 1) as i32;
            n = n >> 1; 
        }

        hamming_weight
    }
}