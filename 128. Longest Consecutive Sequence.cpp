// brute - n^2

// nlogn
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1;
        int ans=INT_MIN;
        int curr=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) curr++;
            else if(nums[i]==nums[i-1]){
                ans=max(ans,curr);
                continue;
            }else
                curr=1;
            ans=max(curr,ans);
        }
        return ans;
    }
};

//set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;

        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans=INT_MIN;
        int curr=1;
        for(auto &it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int c=it;
                while(st.find(c+1)!=st.end()){
                    count++;
                    c=c+1;
                }
                ans=max(count,ans);
            }
        }
        return ans;
    }
};
