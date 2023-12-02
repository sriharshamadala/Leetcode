impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let mut bit_count: Vec<i32> = vec![0; (n+1) as usize];
        for num in (1..=n) {
            // if num is odd
            if num % 2 == 1 {
                bit_count[num as usize] = bit_count[(num / 2) as usize] + 1;
            }
            else {
                bit_count[num as usize] = bit_count[(num / 2) as usize];
            }
        }

        bit_count
    }
}