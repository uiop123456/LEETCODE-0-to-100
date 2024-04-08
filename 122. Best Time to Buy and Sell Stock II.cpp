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
    int solve(vector<int>& nums,int buy,int index,vector<vector<int>>&dp){
        if(index>=nums.size())return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit;
        if(buy){
            int buy_item=-nums[index] + solve(nums,0,index+1,dp);
            int not_buy_item=solve(nums,1,index+1,dp);
            profit=max(buy_item,not_buy_item);
        }else{
            int book_profit=nums[index] + solve(nums,1,index+1,dp);
            int not_book_profit=solve(nums,0,index+1,dp);
            profit=max(book_profit,not_book_profit);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& nums) {
        int buy=1;
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return solve(nums,buy,0,dp);
    }
};
