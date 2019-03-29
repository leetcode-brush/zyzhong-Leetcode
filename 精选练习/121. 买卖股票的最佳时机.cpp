// 动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int res = 0;
        int minp = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            minp = min(prices[i], minp);
            res = max(res, prices[i] - minp);
        }
        return res;
    }
};