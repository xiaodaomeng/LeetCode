/*
Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    //time O(n^2),space O(n)
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i=0;i<=rowIndex;i++){ //k-1 row
            for(int j=i-1;j>0;j--){
                res[j] += res[j-1];
            }
            res.push_back(1);
        }
        return res;
    }
};
