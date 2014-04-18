/*
Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
public:
    //time O(n),space O(1)
    int maxProfit(vector<int> &prices) {
        int minindex=0;
        int res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[minindex]){
                minindex=i;
            }
            res = max(res,(prices[i]-prices[minindex]));
        }
        return res;
    }
};
