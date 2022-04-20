class Solutionrecur {
public:
    int helper(vector<int>& nums, int index){
        if (index >= nums.size()) return 0;
        
        int rob = nums[index] + helper(nums, index+2);
        int dontrob = helper(nums, index+1);
        return std::max(rob, dontrob);
    }
    int rob(vector<int>& nums) {
        return helper(nums, 0);
    }
};

class SolutionMemo {
public:
    int helper(vector<int>& nums, int index, vector<int>& memo){
        if (index >= nums.size()) return 0;
        
        if (memo[index]==-1){
        int rob = nums[index] + helper(nums, index+2, memo);
        int dontrob = helper(nums, index+1, memo);
        memo[index] = std::max(rob, dontrob);
        }
        return memo[index];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(nums, 0, memo);
    }
};

class Solution {
public:
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::max(nums[0], nums[1]);
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i=2; i < nums.size(); i++){
            dp[i] = std::max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
