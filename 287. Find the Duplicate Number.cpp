// tle n^2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]) return nums[i];
            }
        }
        return 0;
    }
};

// nlogn + n accept
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return 0;
    }
};

// with extra space - map
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto c:mp){
            if(c.second>1) return c.first;
        }
        return 0;
    }
};

// IDK why wrong
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        long long sum = static_cast<long long>(n) * (n + 1) / 2;
        for (int i = 0; i <= n; i++) {
            sum -= nums[i];
        }
        return abs(static_cast<int>(sum));
    }
};

// set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto c:nums){
            if(st.find(c)!=st.end()) return c;
            else st.insert(c);
        }
        return -1;
    }
};

// auxilary array of 1 to n size 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>arr(nums.size());
        for(auto x: nums){
            arr[x]++;
            if(arr[x]>1) return x;
        }
        return -1;
    }
};

// modifing the array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            } else {
                return abs(nums[i]);
            }
        }

        return -1;
    }
};

// totoise rabbit || slow fast pointer = slow 1 point, fast 2 point
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        //remember it fast = 0 not nums[0];
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
