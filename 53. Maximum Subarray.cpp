// TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int curr=0;
            for(int j=i;j<nums.size();j++){
                curr+=nums[j];
                maxi=max(maxi,curr);
            }
        }
        return maxi;
    }
};
