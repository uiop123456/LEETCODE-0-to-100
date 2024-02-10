// IDK what's wrong in my code. some testcase passed some not
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& nums,vector<vector<int>>& dp){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0 || nums[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int left=solve(row-1,col,nums,dp);
        int right=solve(row,col-1,nums,dp);
        return dp[row][col]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int row=nums.size();
        int col=nums[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(row-1,col-1,nums,dp);
    }
};

// this runs but the previous one not. IDK why . almost both are same
// -----3 = you've to place this check at the last. not in the first like before
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& nums,vector<vector<int>>& dp){
        if (row < 0 || col < 0) return 0; 
        if (nums[row][col] == 1) return 0; 
        
        if (row == 0 && col == 0) return 1; //------3
        
        if (dp[row][col] != -1) return dp[row][col];

        int left=solve(row-1,col,nums,dp);
        int right=solve(row,col-1,nums,dp);
        return dp[row][col]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int row=nums.size();
        int col=nums[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(row-1,col-1,nums,dp);
    }
};
