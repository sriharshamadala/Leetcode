impl Solution {
    pub fn find_buildings(heights: Vec<i32>) -> Vec<i32> {
        let mut max_height_so_far = 0;
        let mut result = Vec::new();
        let n = heights.len();

        // .rev().enumerate() gives us reversed indices
        for (index, height) in heights.iter().enumerate().rev() {
            if *height > max_height_so_far {
                result.push(index as i32);
                max_height_so_far = *height;
            }
        }

        // Since we need to sort the output in increasing order O(n)
        result.reverse();
        result
        //return result.into_iter().rev().collect();
    }
}