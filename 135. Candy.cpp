class Solution {
public:
    int candy(vector<int>& nums) {
        vector<int>temp(nums.size(),1);
        // L2R
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) temp[i]=temp[i-1]+1;
        }
        // R2L
        int ans=temp[nums.size()-1];
        for(int j=nums.size()-2;j>=0;j--){
            if(nums[j]>nums[j+1]){
                temp[j]=max(temp[j],temp[j+1]+1);
            }
            ans+=temp[j];
        }
        return ans;
    }
};
