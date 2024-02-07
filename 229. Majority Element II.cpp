class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int maj1 = 0, maj2 = 0;
        
        // Step 1: Find candidates for majority elements
        for (auto c : nums) {
            if (maj1 == c)
                count1++;
            else if (maj2 == c)
                count2++;
            else if (count1 == 0) {
                maj1 = c;
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = c;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Step 2: Count occurrences of candidates
        count1 = 0;
        count2 = 0;
        for (auto c : nums) {
            if (c == maj1)
                count1++;
            else if (c == maj2)
                count2++;
        }
        
        // step 3: verify wheather it's freq is greater than n/3 or not
        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3)
            result.push_back(maj1);
        if (count2 > n / 3)
            result.push_back(maj2);
        
        return result;
    }
};
