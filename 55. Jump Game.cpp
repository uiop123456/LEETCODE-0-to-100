class Solution {
public:
    bool solve(int i, vector<int>& nums,vector<int>&dp) {
        if (i >= nums.size() - 1) return true;
        if(dp[i] != -1) return dp[i];

        int canJump = nums[i];
        for (int j = i + 1; j <= i + canJump && j < nums.size(); j++) {
            if(solve(j,nums,dp)){
                return dp[j] = true; 
            }
        }
        return dp[i]=false; 
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(0, nums,dp);
    }
};

int needInd = nums.size()-1;

for(int i=needInd -1;i>=0;i--){
  if(needInd <= nums[i]+1) needInd = i;
 }
return needInd == 0;
