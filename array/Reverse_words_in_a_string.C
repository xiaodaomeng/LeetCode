/*
Reverse Words in a String 
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/
class Solution {
public:
    void reverseWords(string &s) {
        //method 1: time O(n), space O(n)
        string tmp;
        for(int i=s.size()-1;i>=0;){
            while(s[i]==' '&&i>=0) i--;//don't consider the space in the righthand side
            if(i<0) break;
            if(!tmp.empty()) tmp.push_back(' ');
            string word;
            while(s[i]!=' '&&i>=0){
                word.push_back(s[i]);
                i--;
            }
            reverse(word.begin(),word.end());
            tmp.append(word);
        }
        s=tmp;
    }
};
