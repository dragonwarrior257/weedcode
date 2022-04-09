/*
* Idea here is to use sliding window technique.
* keep increasing the window till 2 distinct character crosses.
* then keep decreasing it till again you reach 2 distinct char.
* like expansion and shrinking.
* TIME: O(n)
* SPACE: O(1) hash table stores at max 3 distinct character.
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start{};
        int maxlen = INT_MIN;
        std::unordered_map<int, int> hash;
        
        for(int end{}; end < fruits.size(); end++){
            int c = fruits[end];
            hash[c] += 1;
            while (hash.size() > 2){
                int ch = fruits[start];
                hash[ch] -= 1;
                if (hash[ch] == 0) hash.erase(ch);
                start++;
            }
            maxlen = std::max(maxlen, end-start+1);
        }
        return maxlen;
    }
};
