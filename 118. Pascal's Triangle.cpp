class Solution {
public:
    vector<vector<int>> generate(int row) {
        vector<vector<int>>nums(row);
        for(int i=0;i<row;i++){
            nums[i].resize(i+1,1);
            for(int j=1;j<i;j++){
                nums[i][j] = nums[i-1][j-1]+nums[i-1][j];
            }
        }
        return nums;
    }
};
