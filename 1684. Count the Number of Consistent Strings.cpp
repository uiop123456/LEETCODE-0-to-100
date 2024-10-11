class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        vector<int>arr(26,0);
        for(int i=0;i<allowed.size();i++){
            arr[allowed[i]-'a']++;
        }
        for(int i=0;i<words.size();i++){
            bool check=false;
            for(auto n: words[i]){
                if(!arr[n - 'a']){
                    check=true;
                    break;
                }
            }
            if(!check)ans++;
        }
        return ans;
    }
};
