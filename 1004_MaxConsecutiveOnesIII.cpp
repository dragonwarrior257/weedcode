/* Idea here is 424_LongestRepeatingCharacterReplacement*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen{};
        int start{};
        std::unordered_map<int, int> hash;
        for (int end{}; end < nums.size(); end++){
            hash[nums[end]] += 1;
            int replace = end-start+1 - hash[1];
            if (replace > k){
                while(nums[start]) {
                    hash[1] -= 1;
                    start++;
                }
                hash[0] -= 1;
                start++;
            }
            maxlen = std::max(maxlen, end-start+1);
        }
        return maxlen;
    }
};
/*
idea here is to use  424_LongestRepeatingCharacterReplacement
*/
class Solution_Brute {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen{};
        
        for (int i{}; i<nums.size(); i++){
            std::unordered_map<int, int> hash;
            for (int j=i; j<nums.size(); j++){
                hash[nums[j]] +=1;
                int replace = j-i+1 - hash[1];
                if (replace <= k){
                    maxlen = std::max(maxlen, j-i+1);
                }
            }
        }
        return maxlen;
    }
};
