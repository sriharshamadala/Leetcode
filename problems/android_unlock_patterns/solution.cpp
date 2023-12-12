class Solution {
public:
    int dfs (int curr_num, int rem_dep, bool * vis, int skip[10][10]) {
        // terminal cond
        if (rem_dep == 0) return 1;
        if (rem_dep < 0) return 0;
        vis[curr_num] = true;
        int result = 0;
        for (int ii = 1; ii <= 9; ++ii) {
            // evaluate every num as the potential next step.
            if ((!vis[ii]) && ((skip[curr_num][ii] == 0) || (vis[skip[curr_num][ii]]))) {
                result += dfs(ii, rem_dep - 1, vis, skip);
            }
        }
        vis[curr_num] = false;
        return result;
    }
    void printVis (bool * vis) {
        for (int ii = 1; ii < 10; ++ii) {
            cout << vis[ii] << " ";
        }
        cout << endl;
    }
    
    int numberOfPatterns(int m, int n) {
        int result = 0;
        bool vis[10];
        // XXX vis[0] has to be false.
        for (int ii = 0; ii < 10; ++ii) {
            vis[ii] = false;
        }
        
        int skip[10][10];
        for (int ii = 0; ii < 10; ++ii) {
            for (int jj = 0; jj < 10; ++jj) {
                skip[ii][jj] = 0;
            }
        }
        
        skip[1][3] = 2; skip[3][1] = 2;
        skip[1][7] = 4; skip[7][1] = 4;
        skip[3][9] = 6; skip[9][3] = 6;
        skip[7][9] = 8; skip[9][7] = 8;
        skip[1][9] = 5; skip[9][1] = 5; 
        skip[2][8] = 5; skip[8][2] = 5; 
        skip[4][6] = 5; skip[6][4] = 5;
        skip[3][7] = 5; skip[7][3] = 5;
        
        for (int ii = m; ii <= n; ++ii) {
            result += dfs(1, ii - 1, vis, skip) * 4;
            //cout << result << endl;
            result += dfs(2, ii - 1, vis, skip) * 4;
            //cout << result << endl;
            result += dfs(5, ii - 1, vis, skip);
            //cout << result << endl;
        }
        
        return result;            
    }
};