class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(int i=0;i<logs.size();i++){
            if(ans>0 && logs[i] == "../") ans--;
            else if(logs[i] != "../" && logs[i] != "./") ans++;
        }
        return ans;
    }
};
