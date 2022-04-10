/*
this is modified version of below brute force.
TIME: O(nmk) n= outer loop, m=inner loop, k= wordlen
SPACE: O(n) n= number of words
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordlen = words[0].size();
        int wordcount = words.size();
        
        if (s.size() < wordlen*wordcount) return result;
        
        std::unordered_map<string,int> hash;
        for (auto word: words) hash[word]++;
        
        //outer loop runs everyindex at which match should be tried.
        for (int outer=0; outer<=s.size()-wordcount*wordlen; outer++){
            std::unordered_map<string,int> currhash;
            //inner loop match all the words in pattern.
            // hence keeps new hash to track words matched till now.
            for(int j=0; j<wordcount; j++){
                int nextindex = outer+j*wordlen;
                string ss = s.substr(nextindex, wordlen);
                // if word not found in pattern,no point of proceeding.
                if (hash.find(ss) == hash.end()) 
                    break;
                currhash[ss]++;
                // if word count increase from what is there in pattern,
                // mismatch is found, don't proceed.
                if (currhash[ss] > hash[ss]) 
                    break;
                // total words match with the pattern, update result
                if (j+1 == wordcount) 
                    result.push_back(outer);
            }
        }
        return result;
    }
};

/*
Idea here is to check every i for the pattern of word in words list.
if any word match at i, jump sizeof word steps and again match.
if all words match, record the position.
if not break.
TIME: O(nm)
SPACE: O(m)
*/
class SolutionBrute {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordlen = words[0].size();
        
        for(int i=0; i<s.size(); i++){
            std::unordered_map<string, int> hash;
            for (auto s: words) hash[s]++;
            int match{};
            
            for (int j=i; j<s.size(); j+=wordlen){
                string temp = s.substr(j, wordlen);
                if (hash.find(temp) != hash.end()){
                    if (hash[temp] !=0){
                        hash[temp]--;
                        if (hash[temp]==0) match++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
                if (hash.size() == match) {
                    result.push_back(i);
                    break;
                }
                
            }
        }
        return result;
    }
};
