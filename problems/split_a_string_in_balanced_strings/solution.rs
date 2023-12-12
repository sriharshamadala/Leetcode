impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut l_count_curr: u64 = 0;
        let mut r_count_curr: u64 = 0;
        let mut balanced_substr_count: i32 = 0;
        
        for letter in s.chars() {
            match letter {
                // Should we worry about case?
                'L' => l_count_curr += 1,
                'R' => r_count_curr += 1,
                _ => println!("Invalid Input")
            }
            
            if l_count_curr == r_count_curr {
                balanced_substr_count += 1;
                l_count_curr = 0;
                r_count_curr = 0;
            }
        }
        
        balanced_substr_count
    }
}