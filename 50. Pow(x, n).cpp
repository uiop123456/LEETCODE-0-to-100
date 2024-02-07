//LOL
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};

// 1--> check the power is -ve or not if -ve then do 1/x and make the power positive.. just like x^-1 = (1/x)^1
// 2--> 
// 3--> loop until power becomes zero not the number. number will never become zero. the power will decrease time to time.
// 4--> if odd do 1 extra calcution for one time. multiply the ans with the number. just like x^3 = x^2 * x;
// 5--> devide the power by 2 using shift operator
class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1 / x;                //----> 1
        }       
        long pow = abs(n);            //---->2
        double ans = 1;        
        while(pow){                   //---->3
            if(pow & 1) { //check odd ------>4
                ans *= x;
            }            
            x *= x;
            pow >>= 1;                // --->5
        }        
        return ans;
    }
};
