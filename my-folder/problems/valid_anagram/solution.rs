use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut letter_freq = HashMap::<char, isize>::new();

        for letter in s.chars() {
            // If letter exists increment count by one, else insert with count=1
            *letter_freq.entry(letter).or_insert(0) += 1;
        }

        // verify target is anagram        
        for letter in t.chars() {
            if let Some(count) = letter_freq.get_mut(&letter) {
                *count -= 1;
            }
            else {
                return false;
            }
        }

        // If map is empty, target is a valid anagram of source
        letter_freq.into_values().all(|count| count == 0)
    }
}