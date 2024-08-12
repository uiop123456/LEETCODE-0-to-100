class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i >= nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];

        int canJump = nums[i];
        int minJump = INT_MAX;
      
        for(int j=i+1;j<= i + canJump && j<nums.size();j++){
            int calculateJump = solve(j,nums,dp);
            if(calculateJump != INT_MAX){
                minJump = min(calculateJump+1,minJump);
            }
        }
        return dp[i] = minJump;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};
