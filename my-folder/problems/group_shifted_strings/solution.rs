impl Solution {
    pub fn group_strings(strings: Vec<String>) -> Vec<Vec<String>> {
        let mut strings_iter = strings.into_iter();

        // Unwrap because the pblm guarantees that strings len >= 1
        let mut result = vec![vec![strings_iter.next().unwrap()]];

        while let Some(input_string) = strings_iter.next() {
            if let Some(output_string_list) = result.iter_mut().find(|output_string_list| Solution::are_in_seq(&output_string_list[0], &input_string)) {
                output_string_list.push(input_string);
            }
            else {
                result.push(vec![input_string]);
            }        
        }

        return result;
    }

    pub fn are_in_seq(str1: &String, str2: &String) -> bool {
        // len() returns number of bytes and not chars. 
        // we are assuming the input is all ascii and so we can use this O(1) operation 
        if (str1.len() != str2.len()) || (str1.len() == 0) {
            return false;
        }

        let mut str1_iter = str1.chars();
        let mut str2_iter = str2.chars();
        let offset:i16 = (str1_iter.next().unwrap() as i16) - (str2_iter.next().unwrap() as i16);

        // One-liner; only in nightly
        // str1_iter.eq_by(&str2_iter, |&str1_char, &str2_char| *str1_char - *str2_char == offset)
    
        while let Some(str1_char) = str1_iter.next() {
            let curr_offset:i16 = (str1_char as i16) - (str2_iter.next().unwrap() as i16);
            // handling the circular case
            if (curr_offset != offset) && (curr_offset - offset != 26) && (curr_offset - offset != -26) {
                return false;
            }
        }

        return true;
    }
}