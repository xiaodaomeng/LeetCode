/*
Anagrams
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {
public:
    //time O(n),space O(n)
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string,vector<int>> table;//string as key, vector<int> record the anagrams index
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            table[s].push_back(i);
        }
        for(auto it=table.begin();it!=table.end();it++){
            if((it->second).size()>1){
                for(int i=0;i<(it->second).size();i++){
                    res.push_back(strs[it->second[i]]);
                }
            }
        }
        return res;
    }
};
