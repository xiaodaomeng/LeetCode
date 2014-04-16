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
    //By comparing the medians of two arrays, time O(log(m+n)), space O(log(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m>n) return findMedianSortedArrays(B,n,A,m);//A is always a smaller array
        if(m==0){
            if(n==0) return 0;
            if(n%2!=0) return B[n/2];
            else return (B[n/2-1]+B[n/2])/2.0;
        }
        else if(m==1){
            if(n==1) return MO2(A[0],B[0]);
            if(n%2!=0) return MO2(B[n/2],MO3(A[0],B[n/2-1],B[n/2+1]));
            else return MO3(A[0],B[n/2-1],B[n/2]);
        } 
        else if(m==2){
            if(n==2) return MO4(A[0],A[1],B[0],B[1]);
            if(n%2!=0) return MO3(B[n/2],max(A[0],B[n/2-1]),min(A[1],B[n/2+1]));
            else return MO4(B[n/2],B[n/2-1],max(A[0],B[n/2-2]),min(A[1],B[n/2+1]));
        }
        else if(m==2&&n==2) return (max(A[0],B[0])+min(A[1],B[1]))/2.0;
        int indexA=(m-1)/2;
        int indexB=(n-1)/2;
        //if(A[indexA]==B[indexB]) return A[indexA];
        if(A[indexA]<=B[indexB]){
            return findMedianSortedArrays(A+indexA,m/2+1,B,n-indexA);
        }
        else{
            return findMedianSortedArrays(A,m/2+1,B+indexA,n-indexA);
        }
    }
    double MO2(int a,int b){
        return (a+b)/2.0;
    }
    double MO3(int a,int b,int c){
        return a+b+c-max(a,max(b,c))-min(a,(min(b,c))); 
    }
    double MO4(int a,int b,int c,int d){
        int maxtmp=max(a,max(b,max(c,d)));
        int mintmp=min(a,min(b,min(c,d)));
        return (a+b+c+d-maxtmp-mintmp)/2.0;
    }
};
