class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int nf_rows = grid.size();
        int result = 0;
        if (nf_rows == 0) {return result;}
        int nf_cols = grid[0].size();
        
        for (int ii = 0; ii < nf_rows; ++ii) {
            for (int jj = 0; jj < nf_cols; ++jj) {
                if (grid[ii][jj] == 1) {
                    // up
                    if (ii > 0) {
                        if (grid[ii - 1][jj] == 0) result++;
                    } else {
                        result++;
                    }
                    // down
                    if ((ii + 1) < nf_rows) {
                        if (grid[ii + 1][jj] == 0) result++;
                    } else {
                        result++;
                    }
                    // right
                    if ((jj + 1) < nf_cols) {
                        if (grid[ii][jj + 1] == 0) result++;
                    } else {
                        result++;
                    }
                    // left
                    if (jj > 0) {
                        if (grid[ii][jj - 1] == 0) result++;
                    } else {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};