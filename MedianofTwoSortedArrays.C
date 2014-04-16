/*
Median of Two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
    //By doing binary search for the median, time O(log(m+n)), space O(log(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total=m+n;
        if(total%2!=0) return findkth(A,m,B,n,total/2+1);//(total/2+1) element, not array index 
        else return (findkth(A,m,B,n,total/2)+findkth(A,m,B,n,total/2+1))/2.0;
    }
    double findkth(int A[],int m,int B[],int n,int k){
        if(m>n) return findkth(B,n,A,m,k);//keep smaller array in the front
        if(m==0) return B[k-1];
        if(k==1) return min(A[0],B[0]);
        int i=min(k/2,m);
        int j=k-i;
        int a=A[i-1];
        int b=B[j-1];
        if(a<b) return findkth(A+i,m-i,B,n,k-i);
        else if(a>b) return findkth(A,m,B+j,n-j,k-j);
        else return a;
    }
};
