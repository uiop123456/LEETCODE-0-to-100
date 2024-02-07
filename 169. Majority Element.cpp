// nlogn for sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
// hashmap is easy

// algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int x = 0;
        for(auto c:nums){
            if(count==0) x=c;  //first time it'll always run and x become c and in next line the count will also increase by 1;
            if(x==c) count++;
            else count--;
        }
        return x;
    }
};
