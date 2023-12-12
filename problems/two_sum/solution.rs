use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut is_num_present = HashMap::new();
        let mut result:Vec<i32> = Vec::new();

        for (i,num) in nums.iter().enumerate() {
            is_num_present.insert(num, i);
        }

        for (i,num) in nums.iter().enumerate() {
            match (is_num_present.get(&(target - num))) {
                Some(index) => {
                    // Cannot use the same number twice
                    if (*index == i) {
                        continue;
                    } else {
                        result.push(i as i32);
                        result.push((*index) as i32);
                        //println!("Found {} at {}", target - num, index);
                    }
                    break;
                },
                None => {
                    //println!("Did not find matching num for {}", num);
                    continue
                },
            }
        }

        return result;
    }
}