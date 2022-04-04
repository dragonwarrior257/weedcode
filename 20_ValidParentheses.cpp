/*
 * whenever we get left paren, we push it on stack.
 * whenever we get right paren, we match it and pop from stack.
 * so, if all match happens, at the end stack should be empty.
 * any match didn't happen then stack will not be empty or
 * we try to push right paren on empty stack, both case it is 
 * error.
 * TIME: O(n)
 * SPACE: O(n) 
 */
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if (s[i]==')' && !st.empty() && st.top() == '('){
                st.pop();
            }
            else if (s[i]=='}' && !st.empty() && st.top() == '{'){
                st.pop();
            }
            else if (s[i]==']' && !st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};
