// sliding window once index++ if(sum>target) index--;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0,ans=nums.size()+1;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (ans==nums.size()+1) ?  0:  ans;
    }
};
