class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gl=0,sl=0;
        int ans=0;
        while(gl<g.size() && sl<s.size()){
            if(s[sl] >= g[gl]){
                ans++;
                gl++; //greed is more important here, if I can manage to fill the greed then only increase greed pointer  
            }
            sl++; //otherwise everttime increase the cookies so I can get bigger cokkies on the go
        }
        return ans;
    }
};
