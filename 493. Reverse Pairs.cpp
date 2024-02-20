// TLE noob
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] > 2 * nums[j]) ans++;
            }
        }
        return ans;
    }
};
