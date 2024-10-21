class Solution {
public:
    int minimumOperations(string nums) {
        bool five = false;
        bool zero = false;
        for(int i=nums.size()-1;i>=0;i--){
            // 25, 50, 75, 00 then return size - i - 2
            if(nums[i] == '2' && five) return nums.size() -2 - i;
            if(nums[i] == '5' && zero) return nums.size() -2 - i;
            if(nums[i] == '7' && five) return nums.size() -2 - i;
            if(nums[i] == '0' && zero) return nums.size() -2 - i;
            if(nums[i] == '0' ) zero = true;
            if(nums[i] == '5' ) five = true;
        }
        // If we have a zero, we can form 00 with one operation
        // not found anything
        if(zero) return nums.size() - 1;
        return nums.size();


    }
};
