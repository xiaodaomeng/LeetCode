/*
Permutations 
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int> > permute(vector<int> &num) {
        vector<bool> pos(num.size(),true);//record if the num is permutated in certain position
        vector<int> pum;//intermedia result
        dfs(num,pum,pos);
        return res;
    }
    //method 1: dfs, time O(n!),space O(n)
    void dfs(vector<int> &num,vector<int> &pum,vector<bool> pos){
        if(num.size()==pum.size()){
            res.push_back(pum);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(pos[i]==true){
                pos[i]=false;
                pum.push_back(num[i]);
                dfs(num,pum,pos);
                pum.pop_back();
                pos[i]=true;
            }
        }
    }
    //method 2: next_permutation(num.begin(),num.end()), sort first
};
