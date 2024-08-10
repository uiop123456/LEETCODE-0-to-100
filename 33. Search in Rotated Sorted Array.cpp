class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return mid;
              //left part sorted
            else if(nums[lo]<=nums[mid]){
              //target present in the left part so we exclude the right part by doing high = mid-1;
                if(nums[lo]<=target && target<nums[mid]){
                    hi=mid-1;
                }
                // target present in the right part tho left part sorted but we can't do anything
                else{
                    lo=mid+1;
                }
            }
            // right part sorted
            else{
              // target present in the right part so I don't need the left part so lo ke mid+1 kore di
                if(nums[mid]<target && target<=nums[hi]){
                    lo=mid+1;
                }
                // target is not present in the right part tho right part is sorted but we can't do anyting
                else{
                    hi=mid-1;
                }
            }
        }
      // if not present return -1
        return -1;
    }
};
