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

// if some portion of subarray sum becomes negetive then it's better to exclude that portion of subarr - kadens algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,maxi=INT_MIN;
        for(auto c:nums){
            curr+=c;
            maxi = max(maxi,curr);    
            if(curr<0) curr=0;    // main part
        }
        return maxi;
    }
};
