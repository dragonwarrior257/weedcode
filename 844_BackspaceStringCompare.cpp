/*
This two pointer technique used.
TIME: O(n)
SPACE: O(1)*/
class Solution {
public:
    void getstring(string& s){
        // Init both pointers to start.
        int i=0; // tracking pointer
        int j=0; // traversing pointer.
        // loop till traversing pointer goes outof bound.
        while (j<s.size()){
            // if not # swap i and j.
            if (s[j]!='#') std::swap(s[i++], s[j++]);
            else {
                // if # decrement i to eat letter and incre j.
                if (i > 0) i--;
                j++;
            }
        }
        // get substr to find final string till i pointer.
        s = s.substr(0, i);
    }
    bool backspaceCompare(string s, string t) {
        getstring(s);
        getstring(t);
        return s==t;
    }
};
/*
Idea here is to use the stack.
with every # pop the element if empty, and push if it is not #.
Then pop full string from stack and compare.
TIME: O(n)
SPACE: O(n)
*/
class Solution_stack {
public:
    bool backspaceCompare(string s, string t) {
        std::stack<char> st;
        for (auto ch: s){
            if (ch == '#' && !st.empty()) st.pop();
            else if (ch != '#') st.push(ch);
        }
        s.clear();
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        for (auto ch: t){
            if (ch == '#' && !st.empty()) st.pop();
            else if (ch != '#') st.push(ch);
        }
        t.clear();
        while(!st.empty()){
            t += st.top();
            st.pop();
        }
        return s==t;
    }
};
