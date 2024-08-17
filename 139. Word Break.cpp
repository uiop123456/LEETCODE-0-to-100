class Solution {
public:
    bool canBreak(int i, string &s, unordered_set<string>& wordSet,vector<int>&dp) {
        if (i == s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        
        for (int l = 1; l <= s.size() - i; l++) {
          // taking the substr (leetcode) -> (l, eetcode),(le,etcode),(lee,tcode).....
            string temp = s.substr(i, l);
            // if present then only call for next function otherwise if 'le' is not present in worddict so no point to call fn for 'etcode' ----- && next function call
            if (wordSet.find(temp) != wordSet.end() && canBreak(i + l, s, wordSet,dp)) {
                return dp[l]=true;
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
      // to find if the breaked word is present or not in 0(1) time
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int>dp(301,-1);
        return canBreak(0, s, wordSet,dp);
    }
};
