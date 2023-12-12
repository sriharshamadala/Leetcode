class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int nf_rows = grid.size();
        if (nf_rows <= 1) return 0;
        
        int result = 0;
        int nf_cols = grid[0].size();

        // from col1 -> col2 how many axis aligned rectangles exist.
        int DP[nf_cols - 1][nf_cols - 1];
        memset(&DP[0][0], -1, sizeof(DP));
        
        // Iterate over all possible top-left corners.
        for (int ii = 0; ii < nf_rows - 1; ++ii) {
            for (int jj = 0; jj < nf_cols - 1; ++jj) {
                if (grid[ii][jj] == 1) {
                    // Iterate over all possible top-right corners.
                    for (int kk = jj + 1; kk < nf_cols; ++kk) {
                        if (grid[ii][kk] != 1) continue;
                        if (DP[kk - 1][jj] == -1) {
                            // Iterate over all possible bottom-right corners.
                            for (int ll = ii + 1; ll < nf_rows; ++ll) {
                                if ((grid[ll][kk] == 1) && (grid[ll][jj] == 1)) {
                                    result++;
                                    DP[kk - 1][jj]++;   
                                }
                            }
                            //cout << kk << " " << jj << " " << DP[kk - 1][jj] << ": " << result << endl;
                            // Since we used up one already.
                            //DP[kk - 1][jj]--;
                        } else {
                            result += DP[kk - 1][jj];
                            //cout << kk << " " << jj << " " << DP[kk - 1][jj] << ": " << result << endl;
                            if (DP[kk - 1][jj] > 0) {
                                DP[kk - 1][jj]--;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};