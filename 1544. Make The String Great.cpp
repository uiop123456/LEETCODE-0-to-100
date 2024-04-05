// my 1st thought
class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) { // Check if the characters are the same letter but different cases
                st.pop(); // If they are, pop the character from the stack
            } else {
                st.push(c); // Otherwise, push the character onto the stack
            }
        }
        
        string ans = "";
        while (!st.empty()) {
            ans += st.top(); // Append characters from the stack to the answer string
            st.pop();
        }
        
        reverse(ans.begin(), ans.end()); // Reverse the answer string
        return ans;
    }
};

//updated
class Solution {
public:
    string makeGood(string s) {
        string result;
        for (char c : s) {
            if (!result.empty() && abs(result.back() - c) == 32) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
