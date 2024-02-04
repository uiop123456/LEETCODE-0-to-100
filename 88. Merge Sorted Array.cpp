// classic merge sort algo with extra space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m + n);
        int f = 0, l = 0, k = 0;

        while (f < m && l < n) {
            if (nums1[f] < nums2[l]) {
                nums3[k++] = nums1[f++];
            } else {
                nums3[k++] = nums2[l++];
            }
        }

        while (f < m) {
            nums3[k++] = nums1[f++];
        }

        while (l < n) {
            nums3[k++] = nums2[l++];
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = nums3[i];
        }
    }
};

// TC - n+m most probably
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};
