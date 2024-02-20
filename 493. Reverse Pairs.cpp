// TLE noob
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] > 2 * nums[j]) ans++;
            }
        }
        return ans;
    }
};

// merge sort
class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high,int &ans){ // pass with address
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            ans = ans + j - (mid+1);
        }
        int size = high-low+1;
        vector<int>temp(size,0);
        int left=low,right=mid+1,k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right])
                temp[k++] = nums[left++];
            else
                temp[k++] = nums[right++];
        }
        while(left<=mid){
            temp[k++]=nums[left++];
        }
        while(right<=high)
            temp[k++]=nums[right++];
        int m=0;
        for(int i=low;i<=high;i++){
            nums[i] = temp[m++];
        }
    }
    void mergesort(vector<int>&nums,int low,int high,int &ans){
        if(low>=high){
            return;
        }
        int mid= low+(high-low)/2;
        mergesort(nums,low,mid,ans);
        mergesort(nums,mid+1,high,ans);
        merge(nums,low,mid,high,ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergesort(nums,0,nums.size()-1,ans);
        return ans;
    }
};
