int noOf1 = count(s.begin(),s.end(), '1'), noOf0 = count(s.begin(),s.end(), '0');
return string(noOf1 - 1, '1') + string(noOf0, '0') + '1';

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=count(s.begin(),s.end(),'1');
        string ans(s.size(),'0');
        ans[s.size()-1]='1';
        one--;
        int idx=0;
        while(one--){
            ans[idx++]='1';
        }
        return ans;
    }
};

#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one_count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') one_count++;
        }
        string ans(s.size(),'0');
        int first = 0;
        while (one_count > 0) {
            if (ans[s.size() - 1] != '1'){

                ans[s.size() - 1] = '1';
                one_count--;
            }
            else {
                ans[first] = '1';
                first++;
                one_count--;
            }
            
        }
        return ans;
    }
};
