// IDK what's wrong in my code. some testcase passed some not
class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& nums){
        if(row==0 && col==0) return 1;
        if(row<0 || col<0 || nums[row][col]==1) return 0;
        int left=solve(row-1,col,nums);
        int right=solve(row,col-1,nums);
        return left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int row=nums.size();
        int col=nums[0].size();
        return solve(row-1,col-1,nums);
    }
};
