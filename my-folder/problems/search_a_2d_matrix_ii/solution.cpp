class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nf_rows = matrix.size();
        if (nf_rows == 0) return false;
        int nf_cols = matrix[0].size();
        
        int curr_row = 0;
        int curr_col = nf_cols - 1;
        while ((curr_row < nf_rows) && (curr_col >= 0)) {
            if (target == matrix[curr_row][curr_col]) {
                return true;
            } else if (target > matrix[curr_row][curr_col]) {
                curr_row++;
            } else {
                curr_col--;
            }
        }
        
        return false;
    }
};