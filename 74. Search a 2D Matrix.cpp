// accepted but n^2 not goot. have to use the benifit of already sorted array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int row=nums.size();
        int col=nums[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(nums[i][j]==target) return true;
            }
        }
        return false;
    }
};
// kinda binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int row=nums.size();
        int col=nums[0].size();
        int i=0,j=col-1;
        // i ----> <-----j(upside down)
        while(i<row && j>=0){
            if(nums[i][j]==target) return true;
            else if(nums[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};

// binary nlogn
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int row=nums.size();
        int col=nums[0].size();

        int start=0;
        int end=row*col-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;

            int row_formula = mid/col;
            int col_formula = mid%col;

            if(nums[row_formula][col_formula]<target){
                start=mid+1;
            }else if(nums[row_formula][col_formula]>target){
                end=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
