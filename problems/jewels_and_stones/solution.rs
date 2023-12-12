impl Solution {
    pub fn num_jewels_in_stones(j: String, mut s: String) -> i32 {
        let mut nf_jewels: i32 = 0;
        
        while let Some(stone) = s.pop() {
            for jewel in j.chars() {
                if jewel == stone {
                    nf_jewels += 1;
                    break;
                }           
            }
        }
        nf_jewels
    }
}