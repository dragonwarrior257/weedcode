/*
* Idea here is to use the sliding windown.
* maintain hash to keep check on distinct element.
* gather distinct element and keep expanding window.
* shrink till repeated element is not popped out, as hash
* contain unique element.
* TIME: O(n) + O(n) = O(n) full expansion with full shrink worst case.
* SPACE: O(n) all elements are distinct.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::size_t maxlen = 0;
        int start{};
        std::unordered_set<char> hash;
        
        for(int end{}; end < s.size(); end++){
            char c = s[end];
            while (hash.find(c) != hash.end()){
                char ch = s[start];
                hash.erase(ch);
                start++;
            }
            hash.insert(c);
            maxlen = std::max(maxlen, hash.size());
        }
        return maxlen;
    }
};
