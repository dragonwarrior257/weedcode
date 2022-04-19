/*
TIME: O(n^2)
SPACE: O(n)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        
        dp[0] = nums.size()==1? true: (nums[0]> 0? true: false);
        
        for (int i=1; i < nums.size(); i++){
            for (int j=i-1; j >=0 ; j--){
                if (dp[j] && j+nums[j] >= i){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};
