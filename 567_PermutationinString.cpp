/* 
Idea here is to use the sliding window of size s1 and 
match the s1 with window content.
TIME: O(n)
SPACE: O(1) as there are 26 alphabets only.
*/
class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        std::unordered_map<char,int> hash;
        for (auto ch: s1) hash[ch] += 1;
        
        int start{};
        int match{};
        for (int end{}; end < s2.size(); end++){
            char rightch = s2[end];
            if (hash.find(rightch) != hash.end()){
                hash[rightch] -= 1;
                if (hash[rightch]==0) match++;
            }
            
            if (hash.size()==match) return true;
            
            if (end >=  s1.size()-1){
                char leftch=s2[start];
                if (hash.find(leftch) != hash.end()){
                    if (hash[leftch]==0) match--;
                    hash[leftch] += 1;
                }
                start++;
            }
        }
        return false;
    }
};
/* Idea here is to use the sliding window pattern of size of s2.
we take any window of size s2 and compare all character with pattern.
then we slide the window again further by 1 unit.
TIME: O(n-k) outer loop times O(k) inner loop = O(nk)
SPACE: O(k)
*/
class Solution_fast {
public:
    bool match (vector<int>& a1, vector<int>& a2){
        for (int i=0; i<26; i++){
            if (a1[i] != a2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> array1(26, 0);
        for (auto ch: s1){
            array1[ch-'a'] += 1;
        }
        
        for (int i=0; i<= s2.size()-s1.size(); i++){
            if (array1[s2[i]-'a'] == 0) continue;
            vector<int> array2(26, 0);
            for (int j=0; j < s1.size(); j++){
                array2[s2[i+j]-'a'] += 1;
            }
            if (match(array1, array2)) return true;
        }
        return false;
    }
};
