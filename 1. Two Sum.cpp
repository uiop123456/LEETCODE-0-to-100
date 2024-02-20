// the worst of all and the blood run stale
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {};
    }
};
// umap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            if(umap.find(target-nums[i])!=umap.end()) return {i,umap[target-nums[i]]};
            umap[nums[i]]=i;
        }
        return {};
    }
};

