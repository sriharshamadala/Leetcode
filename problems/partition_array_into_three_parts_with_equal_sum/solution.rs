impl Solution {
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let mut total_sum: i32 = 0;
        for num in &arr {
            total_sum += num;
        }
        
        if (total_sum % 3) != 0 { return false };
        
        let part_sum:i32 = total_sum / 3;
        
        let mut curr_sum:i32 = 0;
        let mut nf_parts:u32 = 0;
        for num in &arr {
            curr_sum += num;
            if (curr_sum == part_sum) {
                nf_parts += 1;
                curr_sum = 0;
            }
        }
        
        nf_parts >= 3
    }
}