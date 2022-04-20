/*
TIME: O(phi^n)
SPACE: O(n)
*/
class SolutionRecur {
public:
    int helper(vector<int>& cost, int num){
        if (num == 0) return 0;
        if (num == 1) return 0;
        
        int one = cost[num-1] + helper(cost, num-1);
        int two = cost[num-2] + helper(cost, num-2);
        return std::min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return helper(cost, cost.size());
    }
};

/*
TIME: O(n)
SPACE: O(n)
*/
class Solutionmemo {
public:
    int helper(vector<int>& cost, int num, vector<int>& memo){
        if (num == 0) return 0;
        if (num == 1) return 0;
        
        if (memo[num]==0){
            int one = cost[num-1] + helper(cost, num-1, memo);
            int two = cost[num-2] + helper(cost, num-2, memo);
            memo[num] = std::min(one,two);
        }
        return memo[num];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, 0);
        return helper(cost, cost.size(), memo);
    }
};

/*
TIME: O(n)
SPACE: O(n)
*/
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        dp[0]=0;
        dp[1]=0;
        for (int i=2; i<=cost.size(); i++){
            int one = cost[i-1] + dp[i-1];
            int two = cost[i-2] + dp[i-2];
            dp[i] = std::min(one, two);
        }
        return dp[cost.size()];
    }
};
