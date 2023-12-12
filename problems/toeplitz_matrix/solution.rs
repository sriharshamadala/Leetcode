impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        if matrix.len() <= 1 {
            return true;
        }

        let nf_rows = matrix.len();
        let nf_cols = matrix[0].len();

        // Traverse with first row as anchors
        for col in 0..nf_cols {
            let offset = col;
            let anchor = matrix[0][col];
            for row in 1..nf_rows {
                if row + offset >= nf_cols {
                    break;
                }
                if (matrix[row][row + offset] != anchor) {
                    return false;
                }
            }
        }

        // Traverse with first col elements as anchors
        for row in 1..nf_rows {
            let offset = row;
            let anchor = matrix[row][0];
            for col in 0..nf_cols {
                if col + offset >= nf_rows {
                    break;
                }
                if (matrix[col + offset][col] != anchor) {
                    return false;
                }
            }
        }
        return true;
    }
}