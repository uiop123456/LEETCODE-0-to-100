// tle w/o dp
class Solution {
public:
    int solve(int row, int col) {
        if (row == 0 && col == 0) return 1;
        if(row<0 || col<0) return 0;
        int left =  solve(row, col - 1);
        int up =  solve(row - 1, col) ; 
        return left + up;
    }

    int uniquePaths(int m, int n) {
        return solve(n - 1, m - 1); 
    }
};

//dp - bottom up
class Solution {
public:
    int solve(int row, int col,vector<vector<int>>&dp) {
        if (row == 0 && col == 0) return 1;
        if(row<0 || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int left =  solve(row, col - 1,dp);
        int up =  solve(row - 1, col,dp) ; 
        return dp[row][col]=left + up;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m - 1, n - 1,dp); 
    }
};
// dp top down
class Solution {
public:
    int uniquePaths(int row, int col) {
        vector<vector<int>>dp(row,vector<int>(col,1));
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
};
