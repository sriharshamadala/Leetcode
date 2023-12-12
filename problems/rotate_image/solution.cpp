class Solution {
public:
    void flipMatrixUpDown(vector<vector<int>>& matrix) {
        int nf_rows = matrix.size();
        if (nf_rows == 0) return;
        int upper_row = 0;
        int lower_row = nf_rows - 1;
        while (lower_row > upper_row) {
            for (int jj = 0; jj < nf_rows; ++jj) {
                int temp = matrix[upper_row][jj];
                matrix[upper_row][jj] = matrix[lower_row][jj];
                matrix[lower_row][jj] = temp;
            }
            lower_row--;
            upper_row++;
        }
    }
    
    void swapSymmetry (vector<vector<int>>& matrix) {
        int nf_rows = matrix.size();
        if (nf_rows == 0) return;
        for (int ii = 0; ii < nf_rows; ++ii) {
            for (int jj = ii + 1; jj < nf_rows; ++jj) {
                // Just the upper triangualr matrix
                int temp = matrix[ii][jj];
                matrix[ii][jj] = matrix[jj][ii];
                matrix[jj][ii] = temp;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        flipMatrixUpDown(matrix);
        swapSymmetry(matrix);
    }
};