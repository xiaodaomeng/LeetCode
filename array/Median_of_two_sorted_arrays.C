/*
Median of Two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    //method 1: similar as binary search, time O(log(m+n)), space O(log(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total=m+n;
        if(total%2!=0) return findkth(A,m,B,n,total/2+1);
        else return (findkth(A,m,B,n,total/2)+findkth(A,m,B,n,total/2+1))/2.0;
    }
    double findkth(int A[], int m, int B[], int n, int k){
        if(m>n) return findkth(B,n,A,m,k);//B is always a larger array
        if(m==0) return B[k-1];
        if(k==1) return min(A[0],B[0]);
        int a_index = min(k/2,m);
        int b_index = k-a_index;
        if(A[a_index-1]<B[b_index-1]){
            return findkth(A+a_index,m-a_index,B,n,k-a_index);
        }
        else if(A[a_index-1]>B[b_index-1]){
            return findkth(A,m,B+b_index,n-b_index,k-b_index);
        }
        else
            return A[a_index-1];
    }
    //method 2: merge, two pointers to count until k, time O(k)
};
