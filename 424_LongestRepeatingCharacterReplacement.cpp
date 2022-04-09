/* Idea here is to use sliding window.
expand the window and find the maxlength by following the 
same replacement criteria as in brute force. 
if it cannot be replaced, shrink the window till valid replacement is found.
TIME: O(n)
SPACE: O(1) as alphabets are constant.
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxlen=0;
        int start=0;
        std::unordered_map<char,int> hash;
        for (int end=0; end < s.size(); end++){
            char c = s[end];
            hash[c] += 1;
            auto it = std::max_element(hash.begin(), hash.end(),
                                      [](auto a, auto b){
                                          return a.second < b.second;
                                      });
            int length = end-start+1;
            int replace = length - it->second;
            if (replace > k){
                char ch = s[start];
                hash[ch] -= 1;
                start++;
            } 
            maxlen = std::max(maxlen, end-start+1);
        }
        return maxlen;
    }
};

/*
Idea here is to find all the contigous substring and check if replacement is possible.
replacement is possible if length of substring - freqOf maxoccuring alphabet.
TIME: O(n^2)
SPACE: O(1) as number of alphabet are constant.
*/
class Solution_brute
{
public:
    int characterReplacement(string s, int k)
    {
        int maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            std::unordered_map<char, int> hash;
            for (int j = i; j < s.size(); j++)
            {
                char c = s[j];
                hash[c] += 1;
                auto it = std::max_element(hash.begin(), hash.end(),
                                           [](auto a, auto b)
                                           {
                                               return a.second < b.second;
                                           });
                int sublength = (j - i + 1);
                int replacelen = sublength - it->second;
                if (replacelen <= k)
                {
                    maxlen = std::max(maxlen, sublength);
                }
            }
        }
        return maxlen;
    }
};
