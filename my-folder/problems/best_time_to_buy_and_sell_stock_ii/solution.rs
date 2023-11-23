impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.len() <= 1 {
            return 0;
        }

        let mut profit = 0;

        let mut cost_price = prices[0];
        for index in 1..prices.len() {
            if prices[index] < prices[index - 1] {
                // Prices fell. Time to sell
                profit += prices[index - 1] - cost_price;
                // Buy low
                cost_price = prices[index];
            }
        }

        // If you haven't sold yet, you have to, on the last day
        profit += prices.last().unwrap() - cost_price;
        return profit;
    }
}