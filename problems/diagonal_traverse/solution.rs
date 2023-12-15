impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let nf_rows = mat.len() as i32;
        let nf_cols = mat[0].len() as i32;
        let mut diag = Vec::with_capacity((nf_rows * nf_cols) as usize);
        let mut row:i32 = 0;
        let mut col:i32 = 0;

        loop{
            // Traverse NE
            loop {
                match (row >= 0, col <= nf_cols-1) {
                    (true, true) => {
                        //println!("{} {}", row, col);
                        diag.push(mat[row as usize][col as usize]);
                        row -= 1;
                        col += 1;
                    },
                    (_, false) => {
                        row += 2;
                        col -= 1;
                        break;
                    },
                    (false, true) => {
                        row += 1;
                        break;
                    },
                }
            }

            if (row >= nf_rows) || (col >= nf_cols) {
                // We are outside the grid. End of traversal
                return diag;
            }

            // Traverse SW
            loop {
                match (row <= nf_rows-1, col >= 0) {
                    (true, true) => {
                        //println!("{} {}", row, col);
                        diag.push(mat[row as usize][col as usize]);
                        row += 1;
                        col -= 1;                        
                    },
                    (true, false) => {
                        col += 1;
                        break;
                    },
                    (false, _) => {
                        row -= 1;
                        col += 2;
                        break;
                    },
                }
            }
        }
    }
}