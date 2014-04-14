/*
Remove Duplicates from Sorted Array Total Accepted: 12964 Total Submissions: 40685 My Submissions
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
class Solution {
public:
    //time O(n),space O(1)
    int removeDuplicates(int A[], int n) {
      if(n==0) return 0;    
      int j=1;
      for(int i=1;i<n;i++){
        if(A[j-1]!=A[i]){
          A[j++]=A[i];
        }
      }
      return j;
    }
};
