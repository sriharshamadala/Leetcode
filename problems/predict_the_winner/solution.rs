impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let (p1_score, p2_score) = Solution::scores_recursive(&nums[..], true);
        if p1_score >= p2_score {
            return true;
        }
        else {
            return false;
        }
    }

    pub fn scores_recursive(nums: &[i32], is_p1: bool) -> (i32, i32) {
        if nums.len() == 0 {
            return (0, 0);
        }
        else {
            if is_p1 {
                // say p1 picks front
                let (mut score1_1, mut score2_1) = Solution::scores_recursive(&nums[1..], false);
                score1_1 += nums.first().unwrap();
                // say p1 picks back
                let (mut score1_2, mut score2_2) = Solution::scores_recursive(&nums[0..nums.len()-1], false);
                score1_2 += nums.last().unwrap();
                if score1_1 > score1_2 {
                    return (score1_1, score2_1);
                }
                else {
                    return (score1_2, score2_2);
                }
            }
            else {
                // p2 picks front
                let (mut score1_1, mut score2_1) = Solution::scores_recursive(&nums[1..], true);
                score2_1 += nums.first().unwrap();
                // say p2 picks back
                let (mut score1_2, mut score2_2) = Solution::scores_recursive(&nums[0..nums.len()-1], true);
                score2_2 += nums.last().unwrap();
                if score2_1 > score2_2 {
                    return (score1_1, score2_1);
                }
                else {
                    return (score1_2, score2_2);
                }
            }
        }
    }
}