class Solution {
public:
    int candy(vector<int>& nums) {
        vector<int>temp(nums.size(),1);
        // L2R
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) temp[i]=temp[i-1]+1;
        }
        // R2L
        int ans=temp[nums.size()-1];
        for(int j=nums.size()-2;j>=0;j--){
            if(nums[j]>nums[j+1]){
                temp[j]=max(temp[j],temp[j+1]+1);
            }
            ans+=temp[j];
        }
        return ans;
    }
};

class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        int ans=n; //everyone must have 1 candy so init all by 1
        int i=1;
        while(i<n){
            // going flat
            if(nums[i]==nums[i-1]){
                i++;
                continue;
            }

            // going up
            int up=0;
            while(nums[i]>nums[i-1]){
                up++;
                ans+=up;
                i++;
                if(i==nums.size()) return ans; //if only monotonic increase array
            }
            // goind down - monotonic decreasing array
            int down = 0;
            while(i<n  && nums[i]<nums[i-1]){
                down++;
                ans += down;
                i++;
            }
            // jeta extra add hochilo oita minus korte hobe
            ans -= min(up,down);
        }
        return ans;
    }
};
