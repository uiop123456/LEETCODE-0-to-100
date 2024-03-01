class Solution {
public:
    vector<int> getRow(int row) {
      // if row=3 then max row no 4 [0 1 2 3] 
        vector<vector<int>>ans(row+1);
        for(int i=0;i<=row;i++){
          // 0 th row - 1 element, 1th row = 2element,
            ans[i].resize(i+1);
            ans[i][0]=1;//first element of the row
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans[i][i]=1;//last element of the row
        }
        return ans[row];
    }
};
