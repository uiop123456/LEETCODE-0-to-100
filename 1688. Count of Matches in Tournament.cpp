class Solution {
public:
    int numberOfMatches(int n) {
        int total_match = 0;
        while(n>1){
            int curr_match = 0;
            if(n%2){ //odd
                n--; //ekta team ke baad
                n/=2; // half lok select hobe only
                curr_match += n + 1; //so half lok can qualify only
            }else{
                n/=2;
                curr_match += n ;
            }
            total_match += curr_match;
        }
        return total_match;
    }
};
