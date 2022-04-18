class SolutionRecur {
public:
    int fib(int n) {
        if (n < 2) return n;
        return fib(n-1) + fib(n-2);
    }
};

class SolutionMemo {
public:
    int fibrecur(vector<int>& memo, int n){
        if (n < 2) return n;
        if (memo[n]!=0) return memo[n];
        memo[n] = fibrecur(memo, n-1) + 
                  fibrecur(memo, n-2);
        return memo[n];
    }
    int fib(int n) {
        vector<int> memo(n+1, 0);
        return fibrecur(memo, n);
    }
};

class Solutiondp {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for (int i=2; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int a = 0;
        int b = 1;
        int c;
        for (int i=2; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
