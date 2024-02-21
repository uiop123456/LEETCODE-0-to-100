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
// vector
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vc;
        for(int i = 0; i < nums.size(); i++) {
            vc.push_back({nums[i], i});
        }
        sort(vc.begin(), vc.end()); 

        int i = 0, j = nums.size() - 1;
        while(i < j) {
            int sum = vc[i].first + vc[j].first;
            if(sum == target) {
                return {vc[i].second, vc[j].second};
            } else if(sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};


