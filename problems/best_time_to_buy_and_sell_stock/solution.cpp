class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() == 0)  return 0;
      
      int min_price = INT_MAX;
      int max_price = INT_MIN;
      int max_price_diff = 0;
      for (auto price : prices) {
        if (price < min_price) {
          min_price = price;
          max_price = price;
        }
        
        if (price > max_price) {
          max_price = price;
        }
        if ((max_price - min_price) > max_price_diff) {
          max_price_diff = (max_price - min_price);
        } 
      }
      
      return max_price_diff;
    }
};