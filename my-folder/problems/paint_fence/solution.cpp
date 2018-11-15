class Solution {
public:
    int numWaysRecur (int n, int k, int depth, bool is_adj_same_color) {
      if (depth == n) {
        // terminal condition
        if (is_adj_same_color) {
          return k - 1;
        } else {
          return k;
        }
      } else {
        if (is_adj_same_color) {
          return (k - 1) * numWaysRecur(n, k, depth + 1, false);
        } else {
          return (k - 1) * numWaysRecur(n, k, depth + 1, false) + numWaysRecur(n, k, depth + 1, true);
        }
      }
    }  
  
    int numWays(int n, int k) {
      if (n == 0) return 0;
      if (n == 1) return k;
      return k * numWaysRecur(n, k, 2, false);
    }
};