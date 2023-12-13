impl Solution {
    pub fn is_palindrome(mut x: i32) -> bool {
        let mut rev_half = 0;

        if (x < 0) || (x % 10 == 0 && x != 0) {
            return false;
        }

        while (x > rev_half) {
            let rem = x % 10;
            x /= 10;
            rev_half = rev_half * 10 + rem; 
        }

        x == rev_half || x == rev_half/10
    }
}