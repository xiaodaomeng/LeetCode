/*
Remove Duplicates from Sorted Array 
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
class Solution {
public:
    //method 1: for loop, time O(n), space O(1)
    int removeDuplicates(int A[], int n) {
        int j=0;
        for(int i=0;i<n;i++){
            if(i==0 || A[i]!=A[i-1]){
                A[j++] = A[i];
            }
        }
        return j;
    }
    //method 2: STL, time O(n), space O(1)

    //unique(first,last) -- O(n)
    //An iterator to the element that follows the last element not removed.
    //The range between first and this iterator includes all the elements in the sequence that were not considered duplicates.
   
    //distance(first,last) -- O(n)
    //The number of elements between first and last.
    int removeDuplicates(int A[], int n) {
        return distance(A,unique(A,A+n));
    }
};
