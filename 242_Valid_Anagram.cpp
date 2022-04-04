// https://leetcode.com/problems/valid-anagram/

/*
An Anagram is rearrangement of original string.
or we can think of it as permutation of original string.
This implies that frequency of each alphabets are 
identical in each anagram. 
so, if we calculate the frequency of each letter in original
string then we can compare other string for same frequency of 
occurence.
we can use hashmap to keep char to frequency mapping or 
char indexed array to frequency.

TIME: O(n) to create hashmap + O(n) compare = O(n)
SPACE: O(n) for hashmap.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        /*If both string are of different length,
         *then they are not permutation of each other.
         */
        if (s.size() != t.size()) return false;
        
        // create hashmap of frequency.
        std::unordered_map<char, int> hash;
        for (auto ch: s){
            hash[ch] += 1;
        }
        
        /* compare string t letters with hashmap and 
         * if found, reduce the freqeuncy of occurence.
         * By end hashmap should be empty as all are compared.
         * if not empty then not an anagram.
         */
        for (auto ch: t){
            if (hash.find(ch) != hash.end()){
                hash[ch] -= 1;
                if (hash[ch] == 0) hash.erase(ch);
            }
            else {
                // as soon as mismatch found, return false.
                return false;
            }
        }
        // check if hash is empty or not.
        return hash.empty();
    }
};
