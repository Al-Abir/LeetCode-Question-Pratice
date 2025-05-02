package Array;

public class Buy_Sell {
    public static int maximumProfit(int prices[]) {
        int buyPrice = Integer.MAX_VALUE;
        int mxProfit = 0;

        for (int i = 0; i < prices.length; i++) {
            if (buyPrice < prices[i]) {
                int profit = prices[i] - buyPrice;
                mxProfit = Math.max(mxProfit, profit);
            } else {
                buyPrice = prices[i];
            }
        }

        return mxProfit; // ✅ return should be outside the loop
    }

    public static void main(String[] args) {
        int[] prices = {7, 1, 5, 3, 6, 4}; 

        int result = maximumProfit(prices);

        System.out.println("Maximum Profit: " + result);
    }
}
