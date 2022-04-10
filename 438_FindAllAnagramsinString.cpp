/*
Idea here is to use sliding window technique with window size equal to pattern.
and at each iteration slid the window one step at time, popping left most element, and adding right most element. 
TIME: O(n) as we visit each element once.
SPACE: O(k) where k is size of pattern.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        
        int start{};
        int match{};
        std::unordered_map<char,int> hash;
        for (auto ch: p) 
            hash[ch]++;
        
        for(int end{}; end < s.size(); end++){
            char rightch = s[end];
            if (hash.find(rightch) != hash.end()){
                hash[rightch]--;
                if (hash[rightch]==0) 
                    match++;
            }
            if (match==hash.size()) 
                result.push_back(start);
            if (end >= p.size()-1){
                char leftch = s[start];
                if (hash.find(leftch) != hash.end()){
                    if (hash[leftch]==0) 
                        match--;
                    hash[leftch]++;
                }
                start++;
            }
        }
        
        return result;
    }
};
/*
Idea here is to check the string of size of pattern beginning at 
every index. current window of size of pattern create hash and match with 
existing hash for equality. if found match record the index.
TIME: O(n-k) times O(k) = O(nk) where k is size of pattern.
SPACE: O(k)
*/
class SolutionBrute {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        
        std::unordered_map<char,int> hashpatt;
        for(auto ch: p) hashpatt[ch]++;
        
        for(int i=0; i<=s.size()-p.size(); i++){
            std::unordered_map<char,int> currpatt;
            for(int j=0; j<p.size(); j++){
                char ch = s[i+j];
                currpatt[ch]++;
            }
            if (currpatt == hashpatt) result.push_back(i);
        }
        return result;
    }
};
