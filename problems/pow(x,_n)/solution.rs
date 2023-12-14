impl Solution {
    pub fn binary_exponentiation(x: f64, n: i64) -> f64 {
        // Terminal conditions
        if n == 1 {
            return x;
        }
        if n == 0 {
            return 1.0;
        }

        
        if n % 2 == 0 { 
            return Solution::binary_exponentiation(x * x, n / 2);
        }
        else {
            return x * Solution::binary_exponentiation(x * x, n / 2);
        }
    }

    pub fn my_pow(x: f64, n: i32) -> f64 {
        // Handle edge cases
        if x == 1.0 {
            return 1.0;
        }

        // Handles overflow when taking abs value
        let n: i64 = n as i64;

        if x == -1.0 {
            return if n % 2 == 0 { 1.0 } else { -1.0 }
        }

        // Recursive binary exponentiation
        return if n < 0 { 1.0 / Solution::binary_exponentiation(x, n.abs()) } else { Solution::binary_exponentiation(x, n) }; 
    }
}