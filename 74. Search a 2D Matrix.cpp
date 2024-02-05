// accepted but n^2 not goot. have to use the benifit of already sorted array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int row=nums.size();
        int col=nums[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(nums[i][j]==target) return true;
            }
        }
        return false;
    }
};
