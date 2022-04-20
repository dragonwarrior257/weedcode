/*
Idea here is to work backward.
Minjump (index) = 1 + Min { Minjump(i) where i belongs [0,index-1] and 
                            there is valid jump possible from i to index }
TIME: O(n^n)
SPACE: O(n)
*/
class Solutionrecur {
public:
    int helper(vector<int>& nums, int index){
        if (index == 0) return 0;
        int minjump = INT_MAX;
        for (int i=index-1; i>=0; i--){
            if (nums[i] >= index-i){
                minjump = std::min(minjump, helper(nums, i));
            }
        }
        return 1+minjump;
    }
    int jump(vector<int>& nums) {
        return helper(nums, nums.size()-1);
    }
};

/*
TIME: O(n^2)
SPACE: O(n)
*/
class SolutionMemo {
public:
    int helper(vector<int>& nums, int index, vector<int>& memo){
        if (index == 0) return 0;
      
        if (memo[index]==-1){
        int minjump = INT_MAX;
        for (int i=index-1; i>=0; i--){
            if (nums[i] >= index-i){
                minjump = std::min(minjump, helper(nums, i, memo));
            }
        }
        memo[index] = 1+minjump;
        }
        return memo[index];
    }
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(nums, nums.size()-1, memo);
    }
};

/*
TIME: O(n^2)
SPACE: O(n)
*/
class Solution {
public:
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0]=0;
        for (int i=1; i<nums.size();i++){
            for(int j=i-1; j>=0; j--){
                if (nums[j] >= i-j )
                   dp[i] = std::min(dp[i], dp[j]);
            }
            dp[i]++;
        }
        return dp[nums.size()-1];
    }
};
