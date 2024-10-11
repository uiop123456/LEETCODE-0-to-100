class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {
        if(m*n != nums.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n));
        int row=0,col=0,i=0;
        while(row < m && i<nums.size()){
            while(col < n){
                ans[row][col]=nums[i];
                i++;
                col++;
            }
            col=0;
            row++;
        }
        return ans;
    }
};
