// noob
sort()

// nlogn
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zero++;
            if(nums[i] == 1) one++;
            if(nums[i] == 2) two++;
        }

        int i = 0;
        while(i < nums.size()) {
            if(zero) {
                nums[i] = 0;
                zero--;
                i++;
            } else if(one) {
                nums[i] = 1;
                one--;
                i++;
            } else {
                nums[i] = 2;
                i++;
            }
        }
    }
};
// n - three pointer Dutch National Flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size() - 1;
        while (one <= two) {
            if (nums[one] == 0) {
                swap(nums[zero], nums[one]);
                zero++;
                one++;
            } else if (nums[one] == 1) {
                one++;
            } else {
                swap(nums[one], nums[two]);
                two--;
            }
        }
    }
};
