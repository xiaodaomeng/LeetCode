/*
3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
public:
    //method 1: time O(n^2),space O(1)
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if(num.size()<3) return res;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2&&num[i]<=0;i++){
            if(i>0 && num[i]==num[i-1]) continue;
            int target = 0-num[i];
            int l=i+1, r=num.size()-1;
            while(l<r){
                int twosum=num[l]+num[r];
                if(twosum<target)
                    l++;
                else if(twosum>target)
                    r--;
                else{
                    vector<int> sub_res;
                    sub_res.push_back(num[i]);
                    sub_res.push_back(num[l]);
                    sub_res.push_back(num[r]);
                    res.push_back(sub_res);
                    l++;
                    r--;
                    while(l<r&&num[l]==num[l-1]) l++;
                    while(l<r&&num[r]==num[r+1]) r--;
                }
            }
        }
        return res;
    }
};
