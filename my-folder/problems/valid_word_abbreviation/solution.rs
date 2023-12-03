impl Solution {
    pub fn valid_word_abbreviation(word: String, abbr: String) -> bool {
        let mut word_iter = word.chars();
        let mut substring_len = 0;

        let mut is_length: bool = false;
        let mut length_start: usize = 0;
        let mut length_end: usize = 0;

        for (index, abbr_char) in abbr.char_indices() {
            //println!("abbr_char = {}", abbr_char);
            if abbr_char.is_ascii_digit() {
                if !is_length {
                    if abbr_char == '0' {
                        return false;
                    }
                    is_length = true;
                    length_start = index;
                }
            }
            else {
                if is_length {                    
                    length_end = index;
                    substring_len = (&abbr[length_start..length_end]).parse().unwrap();
                    is_length = false;
                    // advance iterator
                    //println!("advancing by {}", substring_len);
                    if word_iter.nth(substring_len as usize - 1).is_none() {
                        return false;
                    }
                    substring_len = 0;
                }
                
                if let Some(word_char) = word_iter.next() {                    
                    if (abbr_char != word_char) {
                        // word_char and abbr_char didn't match
                        //println!("word and char mismatch 1");
                        return false;
                    }
                }
                else {
                    //println!("We don't have any chars left in word");
                    return false;
                }
            }
        }

        if is_length {
            length_end = abbr.chars().count();
            substring_len = (&abbr[length_start..length_end]).parse().unwrap();
            return word_iter.count() == substring_len;
        }

        return word_iter.next().is_none();
    }
}