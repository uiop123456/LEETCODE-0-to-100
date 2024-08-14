// l2r - 3 pointer
class Solution {
public:
    bool solve(string &s1, string &s2, string &s3,int i,int j,int k,vector<vector<int>>&dp){
        if(k>=s3.size()) return true;
        if(i>=s1.size() && j>=s2.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        bool takeFromFirst = false;
        bool takeFromSecond = false;
        if(i<s1.size() && s1[i]==s3[k])
            takeFromFirst = solve(s1,s2,s3,i+1,j,k+1,dp);
        if(j<s2.size() && s2[j]==s3[k])
            takeFromSecond = solve(s1,s2,s3,i,j+1,k+1,dp);

        return dp[i][j] = takeFromFirst || takeFromSecond;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};
// r2l - 3 pointer
class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>>& dp) {
        if (k < 0) return true;
        if (i < 0 && j < 0) return false;

        if (dp[i+1][j+1] != -1) return dp[i+1][j+1];

        bool takeFromFirst = false;
        bool takeFromSecond = false;

        if (i >= 0 && s1[i] == s3[k])
            takeFromFirst = solve(s1, s2, s3, i - 1, j, k - 1, dp);
        if (j >= 0 && s2[j] == s3[k])
            takeFromSecond = solve(s1, s2, s3, i, j - 1, k - 1, dp);

        return dp[i+1][j+1] = takeFromFirst || takeFromSecond;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, s3, s1.size()-1, s2.size()-1, s3.size()-1, dp);
    }
};


