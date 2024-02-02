// greedy
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) ans+=(nums[i]-nums[i-1] );
        }
        return ans;
    }
};

//dp tc-2n, sc=2n+matrix
class Solution {
public:
    int solve(vector<int>& nums, int index, int buy, vector<vector<int>>& dp) {
        if (index >= nums.size()) return 0;
        if (dp[index][buy] != -1) return dp[index][buy];
        int profit;
        // if buy possble then there's two option one is buy or not buy
        if (buy==1) {
            int buyProfit = -nums[index] + solve(nums, index + 1, 0, dp);
            int notBuyProfit = solve(nums, index + 1, 1, dp);
            profit = max(buyProfit, notBuyProfit);
        } else {
            int sellProfit = nums[index] + solve(nums, index + 1, 1, dp);
            int notSellProfit = solve(nums, index + 1, 0, dp);
            profit = max(sellProfit, notSellProfit);
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(nums, 0, 1, dp);
    }
};

