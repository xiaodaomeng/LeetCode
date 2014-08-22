/*
Longest Consecutive Sequence 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
class Solution {
public:
    //method 1: unordered_map, time O(n),space O(n)
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,bool> check;
        int longest = 0;
        for(int i=0;i<num.size();i++) check[num[i]]=false;
        for(int i=0;i<num.size();i++){
            if(check[num[i]]==true) continue;
            int length = 1;
            check[num[i]]=true;
            for(int j=num[i]+1;check.find(j)!=check.end();j++){
                check[j]=true;
                length++;
            }
            for(int j=num[i]-1;check.find(j)!=check.end();j--){
                check[j]=true;
                length++;
            }
            longest = max(longest,length);
        }
        return longest;
    }
};
