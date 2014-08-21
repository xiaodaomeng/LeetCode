/*
Search in Rotated Sorted Array II 
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
public:
    //method 1:brute-force, time O(n),space O(1)
    //why not binary search, 1,1,2,3,1,1,1,1,1 can not say ascending array
    bool search(int A[], int n, int target) {
        for(int i=0;i<n;i++){
            if(target==A[i]) return true;
        }
        return false;
    }
};
