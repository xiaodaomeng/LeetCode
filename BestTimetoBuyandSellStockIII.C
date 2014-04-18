/*
Best Time to Buy and Sell Stock III 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    //time O(n),space O(n)
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<int> forward(n,0);
        vector<int> backward(n,0);
        
        int minvalue=prices[0];
        for(int i=1;i<n;i++){
            minvalue=min(minvalue,prices[i]);
            forward[i]=max(forward[i-1],prices[i]-minvalue);
        }
        
        int maxvalue=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxvalue=max(maxvalue,prices[i]);
            backward[i]=max(backward[i+1],maxvalue-prices[i]);
        }
        
        int res=forward[n-1];
        for(int i=0;i<n-1;i++){
            res = max(res,forward[i]+backward[i+1]);
        }
        return res;
    }
};
