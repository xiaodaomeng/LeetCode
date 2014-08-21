/*
Search in Rotated Sorted Array
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    //method 1: binary search, time O(logn), space O(1)
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (right+left)/2;
            if(A[mid]==target) return mid;
            //first half part ascending without pivot 
            if(A[left]<=A[mid]){
                if(A[left]<=target && target<A[mid]) right = mid-1;
                else left = mid+1;
            }   
            //first half part include pivot
            else{
                if(A[mid]<target && target<=A[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};
