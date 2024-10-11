class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        sort(nums.begin(),nums.end());
        return nums[0] + nums[1] <= money ? money - nums[0] - nums[1] : money; 
    }
};
