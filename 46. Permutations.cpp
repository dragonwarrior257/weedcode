/*
idea is to create the permutation tree by recursion and backracking.
TIME: O(!n)
SPACE:O(n. !n)
*/
class Solution {
public:
    void helper(vector<int>& nums, int i, vector<vector<int>>& result){
        if (i==nums.size()-1) {
            result.push_back(nums);
            return;
        }
        for (int k=i; k<nums.size(); k++){
            std::swap(nums[i], nums[k]);
            helper(nums, i+1, result);
            std::swap(nums[i], nums[k]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        helper(nums, 0, result);
        return result;
    }
};
