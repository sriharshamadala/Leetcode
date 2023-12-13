impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <= 0 {
            return false;
        }

        // n & n-1 simply extracts the right-most bit that is set
        // Only powers of two have just one bit set, hence this operation
        // preserves the number
        n & (-n) == n
    }
}