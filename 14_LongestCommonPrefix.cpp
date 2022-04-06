/*
* This is adhoc solution. Idea is if we have prefix for first and second, * then we need to calculate prefix with third and update the prefix.
* LCP(s1, s2)  is LCP(s3, LCP(s1,2)) .....
* TIME: O(n.m)
* SPACE: O(m)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::deque<char> firstq;
        std::deque<char> secondq;
        for (auto ch: strs[0]){
            firstq.push_back(ch);
        }
        for(int i=1; i<strs.size(); i++){
            for (auto ch: strs[i]){
                if (!firstq.empty() && ch == firstq.front()){
                    firstq.pop_front();
                    secondq.push_back(ch);
                }
                else{
                    break;
                }
            }
            if (secondq.empty()) return "";
            firstq = secondq;
            secondq.clear();
        }
        string s;
        while(!firstq.empty()){
            s += firstq.front();
            firstq.pop_front();
        }
        return s;
    }
};
