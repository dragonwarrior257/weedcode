/*
Idea here is to use the recursion and backtracking.
empty list has empty subset.
either element can be taken or it cannot taken.
TIME: O(2^n)
SPACE: O(h) height of recursive stack which is h = n.
*/
class Solution {
public:
    void helper(vector<int>& nums, 
                vector<vector<int>>& result,
                vector<int>& curr, int index){
        
        if (index >= nums.size()){
            result.push_back(curr);
            return;
        }
        // you take it.
        curr.push_back(nums[index]);
        helper(nums, result, curr, index+1);
        //you dont take it.
        curr.pop_back();
        helper(nums, result, curr, index+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        helper(nums, result, curr, 0);
        return result;
    }
};
