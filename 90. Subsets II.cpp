/*
Idea is to collect the result in set, rather than in vector.
set will remove the duplicate. otherwise solution is similar to 
subset problem.
TIME: O(n2^n)
SPACE: O(2^n)
*/
class Solution {
public:
    void helper(vector<int>& nums,
               vector<int>& curr, int index,
               set<vector<int>>& set){
        if (index >= nums.size()){
            set.insert(curr);
            return;
        }
        //pick 
        curr.push_back(nums[index]);
        helper(nums, curr, index+1, set);
        
        // do not pick
        curr.pop_back();
        helper(nums, curr, index+1, set);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // set as collector of subset to remove duplicates.
        set<vector<int>> set;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(nums, curr, 0, set);
        
        vector<vector<int>> result;
        for (auto v: set){
            result.push_back(v);
        }
        return result;
    }
};
