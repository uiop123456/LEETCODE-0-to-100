// L2R
class Solution {
public:
    int solve(string f, string s, int i, int j, vector<vector<int>> &dp){
        if(j == s.size()) return f.size() - i;
        if(i == f.size()) return s.size() - j;

        if(dp[i][j]!=-1) return dp[i][j];

        if(f[i] == s[j]){
            return solve(f, s, i + 1, j + 1, dp);
        }

        int insert = solve(f, s, i, j + 1, dp);
        int del = solve(f, s, i + 1, j, dp);
        int repl = solve(f, s, i + 1, j + 1, dp);

        return dp[i][j] = 1 + min(insert, min(del, repl));
    }

    int minDistance(string f, string s) {
        vector<vector<int>> dp(500,vector<int>(500,-1));
        return solve(f, s, 0, 0, dp);
    }
};

// R2L
class Solution {
public:
    int solve(string &f, string &s,int i,int j, vector<vector<int>> &dp){
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if (f[i] == s[j]) {
            return dp[i][j] = solve(f, s, i - 1, j - 1,dp);
        } 

        int insert = solve(f, s, i, j - 1, dp);
        int delet = solve(f, s, i - 1, j, dp);
        int replace = solve(f, s, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min(insert, min(delet, replace));
    }
    int minDistance(string f, string s) {
        vector<vector<int>> dp(f.size(),vector<int>(s.size(),-1));
        return solve(f,s,f.size()-1,s.size()-1,dp);
    }
};

// btm up
class Solution {
public:
    int minDistance(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1));

        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if(i==0 || j==0){
                    dp[i][j] = i+j; 
                }else if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
        return dp[s.size()][t.size()];
    }
};
