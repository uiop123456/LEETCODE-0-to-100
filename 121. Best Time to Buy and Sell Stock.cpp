// TLE
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ans=max(ans,nums[j]-nums[i]);
            }
        }
        return ans;
    }
};

// better most probaby 
// if you have the power of predicting the future then why not use it perfectly by adding a dummy array and make a count of max_so_far in reverse order traversal
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> dum(nums.size(), 0);
        int max_so_far = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            max_so_far = max(max_so_far, nums[i]);
            dum[i] = max(max_so_far, dum[i]);
        }

        int ans = 0;  
        
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dum[i] - nums[i]);
        }

        return ans;
    }
};

