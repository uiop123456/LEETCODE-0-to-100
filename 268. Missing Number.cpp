// basic math
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        for(auto x:nums){
            sum-=x;
        }
        return sum;
    }
};

//xor
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans=nums.size();
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
            ans ^= i;
        }
        return ans;
    }
};

// cyclic sort
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int current_val = nums[i];
            while (current_val < nums.size() && current_val != i) {
                swap(nums[i], nums[current_val]);
                current_val = nums[i];
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return nums.size(); 
    }
};


// I don't know this algo much, I googled, will do later
class Solution {
public:
    // Function to perform cyclic sort
    void f(vector<int>& a, int i) {
        while (a[i] != i) {
            // Swap elements to put them in their correct positions
            if (a[i] < a.size())
                swap(a[i], a[a[i]]);
            else
                return;  // Avoids infinite loop if the value is out of bounds
        }
    }
    
// Main function to find the missing number
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;  // If the array is empty, the missing number is 0

        int n = nums.size();

        // Perform cyclic sort on the array
        for (int i = 0; i < n; i++) {
            f(nums, i);
        }

        // Iterate through the sorted array to find the first mismatch
        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;  // Return the first mismatch, which is the missing number
        }

        // If all elements are in their correct positions, the missing number is n
        return n;
    }
};
