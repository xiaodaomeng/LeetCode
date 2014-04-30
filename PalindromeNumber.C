/*
Palindrome Number 
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
class Solution {
public:
    //reverse number: time O(1), space O(1)
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0) return false;
        int re_x=0;
        for(int tmp=x;tmp!=0;tmp/=10){
            re_x=(re_x*10)+(tmp%10);
        }
        if(re_x==x) return true;
        else return false;
    }
};
