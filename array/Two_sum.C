/*
Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
public:
    //method 1: unordered_map, time O(n),space O(n)
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int,int> input;
        for(int i=0;i<numbers.size();i++){
            input[numbers[i]]=i;
        }
        for(int i=0;i<numbers.size();i++){
            int t = target-numbers[i];
            if(input.find(t)!=input.end() && i!=input[t]){//caution: not find itself
                res.push_back(i+1);
                res.push_back(input[t]+1);
                break;
            } 
        }
        return res;
    }
};
