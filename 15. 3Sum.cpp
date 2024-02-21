class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3)return ans;

        //1. sort
        sort(nums.begin(),nums.end());
        
        for(int ii=0;ii<nums.size()-2;ii++){
            // 3. Skip fixed index duplicates
            if(ii > 0 && nums[ii] == nums[ii - 1]) {
                continue;
            }

            int i=ii+1,j=nums.size()-1;
            while(i<j){
                int sum=nums[ii]+nums[i]+nums[j];
                if(sum==0){
                    ans.push_back({nums[ii],nums[i],nums[j]});
                    //3. skip fixed index duplicate also
                    while(i<j && nums[i]==nums[i+1])i++;
                    while(i<j && nums[j]==nums[j-1])j--;
                    i++;
                    j--;
                }
                else if(sum<0) i++;
                else j--;
            }
        }
        return ans;
    }
};
