class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int oneStep = solve(n-1,dp);
        int twoStep = solve(n-2,dp);
        return dp[n] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(46,-1);
        return solve(n,dp);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int one_step_back = 2; 
        int two_step_back = 1; 
        int ans = 0;
        for(int i=3;i<=n;i++){
            ans = one_step_back + two_step_back;
            two_step_back = one_step_back;
            one_step_back = ans;
        }
        return ans;
    }
};
