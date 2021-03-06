/*
3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    //method 1: time O(n^2),space O(1)
    int threeSumClosest(vector<int> &num, int target) {
        int res;
        int min_diff=INT_MAX;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size()-2;i++){
            int l=i+1, r=num.size()-1;
            while(l<r){
                int threesum=num[i]+num[l]+num[r];
                if(threesum==target) return target;
                else if(threesum<target) l++;
                else r--;
                if(abs(threesum-target)<min_diff){
                    min_diff = abs(threesum-target);
                    res = threesum;
                }
            }
        }
        return res;
    }
};
