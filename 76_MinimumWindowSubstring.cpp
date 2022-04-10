/*
Idea here is to use the sliding window technique with window of variable size.
window can expand and shrink of variable size.
store the pattern in hash table with freq of letters.
Keep expanding the window till all pattern letters are consumed by the window.
if duplicates are there allow frequency of match go negative.
once match is found, update the minlen of the string and position of match.
Now shrink the window till match is valid.
everytime shrink is made letter is either in hash or not.
if in hash increase the count and check if it is zero to decrease the match count.
TIME: O(n+m)
TIME: O(m)
*/
class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        if (t.size() > s.size()) return result;
        
        int minlen=INT_MAX;
        int minstart=0;
        
        int start{};
        std::unordered_map<char,int> hash;
        for (auto ch: t) hash[ch]++;
        int match{};
        
        for (int end{}; end<s.size(); end++){
            char ch=s[end];
            // if letter in hash, decrease it and update match if possible.
            if (hash.find(ch) != hash.end()){
                hash[ch]--;
                if (hash[ch]==0) match++;
            }
            // check if valid match is reached.
            while (match == hash.size()){
                //update the minlen and position.
                if (end-start+1 < minlen){
                    minlen = end-start+1;
                    minstart = start;
                }
                //shrink the window and update the match 
                char leftch = s[start];
                if (hash.find(leftch) != hash.end()){
                    if (hash[leftch]==0) match--;
                    hash[leftch]++;
                }
                start++;
            }
        }
        return minlen==INT_MAX?result:s.substr(minstart, minlen);
    }
};

/*
Idea here is to match the all possible string starting at each position.
TIME: O(nk)
SPACE: O(k) 
*/
class SolutionBrute {
public:
    string minWindow(string s, string t) {
        string result;
        if (t.size() > s.size()) return result;
        
        int minlen=INT_MAX;
        int minstart=0;
        int minend=0;
        
        for (int i{}; i<s.size(); i++){
            std::unordered_map<char,int> hash;
            for (auto ch: t) hash[ch]++;
            int match{};
            
            for(int j=i; j<s.size(); j++){
                char ch = s[j];
                if (hash.find(ch) != hash.end()){
                    if (hash[ch]!=0){
                        hash[ch]--;
                        if (hash[ch]==0) match++;
                    }
                }
                if (match == hash.size()){
                    if (j-i+1 < minlen){
                        minlen = j-i+1;
                        minstart= i;
                        minend=j;
                        break;
                    }
                }
            } 
        }
        return minlen==INT_MAX?result:s.substr(minstart, minlen);
    }
};
