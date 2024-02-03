// working code
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int row=nums.size();
        for(int i=0;i<row;i++){
            if(ans.empty() || nums[i][0] > ans.back()[1]){
                ans.push_back(nums[i]);
            }else{
                ans.back()[1] = max(ans.back()[1],nums[i][1]);
            }
        }
        return ans;
    }
};


// wrong code maybe some logic error will fix later
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        int ans_row=0;
        int row=nums.size();
        int col=nums[0].size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<row;i+=2){
            for(int j=1;j<col;j+=2){
                if(nums[i][j]>=nums[i+1][j-1]){
                    vector<int>ans2;
                    ans2.push_back(nums[i][j-1]);
                    ans2.push_back(nums[i+1][j+1]);
                    ans[ans_row].push_back(ans2);
                    ans_row++;
                }else{
                    ans[ans_row].push_back({nums[i][j-1],nums[i][j]});
                    ans_row++;
                    ans[ans_row].push_back({nums[i+1][j-1],nums[i+1][j+1]});
                    ans_row++;
                }
            }
        }
        return ans;
    }
}
