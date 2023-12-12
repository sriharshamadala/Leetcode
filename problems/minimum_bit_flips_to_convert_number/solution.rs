impl Solution {
    pub fn nf_bits_set(temp: i32) -> i32 {
        let mut nf_bits:i32 = 0;
        let mut bitmap:i32 = temp;
        while (bitmap != 0) {
            if (bitmap & 0x1 == 1) {
                nf_bits += 1;
            }
            bitmap = bitmap >> 1;
        }
        
        return nf_bits;
    }
    
    pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
        let bitmap:i32 = start ^ goal;
        
        Solution::nf_bits_set(bitmap)
    }
}