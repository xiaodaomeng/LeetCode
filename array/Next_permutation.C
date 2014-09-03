class Solution {
public:
    //method 1: STL, time O(n),space O(1)
    void nextPermutation(vector<int> &num) {
        next_permutation(num.begin(),num.end());
    }
};
