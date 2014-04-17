/*
Reverse Words in a String
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/
//string push_back: append a char
//string append: append a string
class Solution {
public:
    //time O(n), space O(n)
    void reverseWords(string &s) {
        string tmp;
        for(int i=s.size()-1;i>=0;){
            while(s[i]==' '&&i>=0) i--;
            if(i<0) break;
            if(!tmp.empty()) tmp.push_back(' ');
            string word;
            while(s[i]!=' '&&i>=0){
                word.push_back(s[i--]);
            }
            reverse(word.begin(),word.end());
            tmp.append(word);
        }
        s=tmp;
    }
};
