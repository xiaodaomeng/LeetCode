/*
4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
class Solution {
public:
    //method 1: time O(n^3),space O(1)
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        if(num.size()<4) return res;
        sort(num.begin(),num.end());
        int N=num.size();
        for(int i=0;i<N;i++){
            if(i>0 && num[i]==num[i-1]) continue;
            for(int j=i+1;j<N;j++){
                if(j>i+1 && num[j]==num[j-1]) continue;
                int left = target-num[i]-num[j]; 
                int l=j+1,r=N-1;
                while(l<r){
                    int sum = num[l]+num[r];
                    if(sum == left){
                        vector<int> sub_res;
                        sub_res.push_back(num[i]);
                        sub_res.push_back(num[j]);
                        sub_res.push_back(num[l]);
                        sub_res.push_back(num[r]);
                        res.push_back(sub_res);
                        l++;
                        r--;
                        while(l<r&&num[l]==num[l-1]) l++;
                        while(l<r&&num[r]==num[r+1]) r--;
                    }
                    else if(sum<left) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};
