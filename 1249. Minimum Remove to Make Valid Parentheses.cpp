class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int>st;
        unordered_set<int>remove_idx;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                //only ')' no '(' is present so revove those index
                if(st.empty()){
                    remove_idx.insert(i);
                }else{
                    st.pop();
                }
            }
        }
        //onlly '(' no ')' so remove those index too;
        while(!st.empty()){
            remove_idx.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            //jodi kono index remove korar jonne na pai then add the char to ans
            if(remove_idx.find(i)==remove_idx.end()){
                ans+=s[i];
            }
        }
        return ans;

    }
}; 

//2nd without extra space
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                open++;
                ans+=s[i];
            }
            else if(s[i]==')' && open){
                open--;
                ans+=s[i];
            }else if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
        }
        open=0;
        string ans1="";
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]==')'){
                open++;
                ans1+=ans[i];
            } 
            else if(ans[i]=='(' && open){
                open--;
                ans1+=ans[i];
            }else if(ans[i]!='(' && ans[i]!=')'){
                ans1+=ans[i];
            }
        }
        reverse(ans1.begin(),ans1.end());
        return ans1;
    }
};
