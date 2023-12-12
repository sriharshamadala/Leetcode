/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 *  struct BinaryMatrix;
 *  impl BinaryMatrix {
 *     fn get(row: i32, col: i32) -> i32;
 *     fn dimensions() -> Vec<i32>;
 * };
 */

impl Solution {
    pub fn left_most_column_with_one(binaryMatrix: &BinaryMatrix) -> i32 {
         let mat_dims = binaryMatrix.dimensions();
         let nf_rows = mat_dims[0];
         let nf_cols = mat_dims[1];

        /*
        Search by col soln makes too many calls
         for col in 0..nf_cols {
             for row in 0..nf_rows {
                 if binaryMatrix.get(row as i32, col as i32) != 0 {
                     return col as i32;
                 }
             }
         }
         */

        /*
        Search by row, even limiting the max column we search is slow, since I am still doing linear search
        let mut max_col = nf_cols;
         for row in 0..nf_rows {
             for col in 0..max_col {
                 if binaryMatrix.get(row as i32, col as i32) != 0 {
                     max_col = col;
                     break;
                 }
             }
         }

         if max_col == nf_cols {
             return -1;
         }
         else {
             return max_col;
         }
         */

         // Walking the binary matrix
         let mut col = nf_cols - 1;
         let mut row = 0;
         while (row < nf_rows) && (col >= 0) {
             if binaryMatrix.get(row as i32, col as i32) == 1 {
                 col -= 1;
             }
             else {
                 row += 1;
             }
         }

         if col == nf_cols - 1 {
             return -1;
         }
         else {
             return col + 1;
         }
    }
}