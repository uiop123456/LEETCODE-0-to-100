// nice cpp
// backward -> swap -> reverse
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        if (nums.size() == 2) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int n = nums.size() - 1;
        int i = n - 1, j = n;

        for (; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        } else {
            while (j > i) {
                if (nums[j] > nums[i]) break;
                j--;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int first=0,second=nums.size()-1,n=nums.size()-1;
        int i=0;
        bool flag=true;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                first = i;
                flag=false;
                break;
            }
        }
        if(flag) return reverse(nums.begin(),nums.end());
        while(first<second){
            if(nums[first]<nums[second]){
                break;
            }
            second--;
        }
        swap(nums[first],nums[second]);
        second=first+1;
        while(second<n){
            swap(nums[second],nums[n]);
            second++;n--;
        }
        return;
    }
};
