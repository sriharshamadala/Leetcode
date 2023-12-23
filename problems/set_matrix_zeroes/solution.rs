impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let m = matrix.len();
        let n = matrix.first().expect("Input should have atleast one row").len();
        let mut is_col_zero = false;

        // First pass
        for row in 0..m {
            if matrix[row][0] == 0 {
                is_col_zero = true;
            }
            for col in 1..n {
                if matrix[row][col] == 0 {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        // Second pass
        for row in 1..m {
            for col in 1..n {
                if (matrix[row][0] == 0) || (matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        // does first row need to be zeroed?
        if matrix[0][0] == 0 {
            matrix[0] = vec![0; n];
        }

        // does first col need to be zeroed?
        if is_col_zero {
            for row in 0..m {
                matrix[row][0] = 0;
            }
        }
    }
}