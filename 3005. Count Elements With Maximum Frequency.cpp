//double pass
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>ans(101,0);
        int maxF=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
            maxF=max(maxF,ans[nums[i]]);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==maxF)count++; 
        }
        return count*maxF;
    }
};

//single pass
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxF=0;
        int count=0;
        vector<int>ans(101,0);
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
            if(ans[nums[i]]>maxF){
                maxF=ans[nums[i]];
                count=maxF;
            }else if(ans[nums[i]]==maxF){
                count+=maxF;
            }
        }
        return count;
    }
};  

// map
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxF = -1,ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxF = max(maxF,mp[nums[i]]);
        }
        for(auto m:mp){
            if(m.second == maxF){
                ans+=m.second;
            }
        }
        return ans;
    }
};
