/*
 * we use two poniter technique. 
 * Idea is we can have profit only when we buy low and sell high.
 * so we keep two poniters, one buy at 0 and another sell at 1.
 * now compare buy and sell, if sell is greater than buy, update maxprofit,
 * and move sell by 1. again check if sell > buy.
 * Now if sell is less than buy, move buy to sell location and update sell 
 * by 1.
 * TIME : O(n)
 * SPACE : O(1)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==1) return 0;
        
        int buy=0;
        int sell= buy+1;
        int maxprofit = 0;
        while (sell < prices.size()){
            if (prices[sell] > prices[buy]){
                maxprofit = std::max(maxprofit, prices[sell]-prices[buy]);
                sell++;
            }
            else{
                buy=sell;
                sell=buy+1;
            }
        }
        return maxprofit;
    }
};


/*
 * Use kadanes algorithm to profit diff array. 
 */
class Solution_dp {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        vector<int> stockdiff;
        for (int i=1; i<prices.size(); i++){
            stockdiff.push_back(prices[i]-prices[i-1]);
        }
        int globalmax = stockdiff[0];
        int currmax = stockdiff[0];
        for (int i=1; i< stockdiff.size(); i++){
            currmax = std::max(stockdiff[i], stockdiff[i]+currmax);
            globalmax = std::max(globalmax, currmax);
        }
        return (globalmax<0)? 0:globalmax;
    }
};
