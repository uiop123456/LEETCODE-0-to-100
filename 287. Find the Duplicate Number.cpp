// with extra space
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
