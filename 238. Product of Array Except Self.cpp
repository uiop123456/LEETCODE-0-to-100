class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()<=1) return nums;
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        left[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            left[i]=left[i-1]*nums[i];
        }
        right[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            right[i]=right[i+1]*nums[i];
        }
        nums[0]=right[1],nums[nums.size()-1]=left[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++){
            nums[i]=left[i-1]*right[i+1];
        }
        return nums;
    }
};
