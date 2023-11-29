impl Solution {
    pub fn reverse_bits(mut x: u32) -> u32 {        
        // index is LSB = 0; MSB = 31;
        const MSB: u32 = 32;
        for index in 0..(MSB/2) {
            Solution::swap(&mut x, index, MSB-index-1)
        }

        x
    }

    // This function swaps the bits at index 1 and 2 of num
    fn swap(num: &mut u32, index1: u32, index2: u32) {
        let index1_map: u32 = 1 << index1;
        let index2_map: u32 = 1 << index2;

        let index1_bit = (*num & index1_map) >> index1;
        let index2_bit = (*num & index2_map) >> index2;

        // Clear the bits
        *num = *num & (!index1_map);
        *num = *num & (!index2_map);
        // Swap the bits
        *num = *num | ((index1_bit << index2) | (index2_bit << index1));
    }
}