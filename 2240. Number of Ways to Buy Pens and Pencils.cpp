class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int time = total/cost1 ;
        long long ans= 0;
        for(int i=0;i<=time; i++){
            ans += (((total-(i * cost1))/cost2)+1);
        }
        return ans;
    }
};
