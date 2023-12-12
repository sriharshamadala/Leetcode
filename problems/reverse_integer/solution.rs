impl Solution {
    // Assuming we can't store u64 or i64
    pub fn my_checked_mul(a: i32, b: i32) -> Option<i32> {
        if (a == 0) | (b == 0) {
            return Some(0);
        }

        match (a > 0, b > 0) {
            (true, true) | (false, false) => {
                // we only need to check for overflow
                if a > (i32::MAX / b) {
                    return None;
                }
            },
            (true, false)  => {
                // We only need to check for underflow                
                if a > (i32::MIN / b) {
                    return None;
                }
            },
            (false, true) => {
                // We only need to check for underflow
                if b > (i32::MIN / a) {
                    return None;
                }
            },
        }

        Some(a * b)
    } 

    pub fn my_checked_add(a:i32, b:i32) -> Option<i32> {
        if b >= 0 {
            // We only need to check for overflow
            if a > (i32::MAX - b) {
                return None;
            }
        }
        else {
            // We only need to check for underflow
            if a < (i32::MIN - b) {
                return None;
            }

        }

        Some(a + b)
    }

    pub fn reverse(mut x: i32) -> i32 {
        let mut res:i32 = 0;
        while x != 0 {
            let rem = x % 10;
            x /= 10;

            if let Some(r) = res.checked_mul(10).and_then(|p| Solution::my_checked_add(p, rem)) {                
                res = r
            }
            else {
                return 0;
            }
        }

        res
    }
}