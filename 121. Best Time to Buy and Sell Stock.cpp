// TLE
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ans=max(ans,nums[j]-nums[i]);
            }
        }
        return ans;
    }
};
