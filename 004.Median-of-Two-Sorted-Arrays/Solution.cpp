class Solution {
public:
    double findkth(int A[],int m,int B[],int n,int k){
        if(m>n)   //确保数组A长度比B短，非常好用的方法
            return findkth(B,n,A,m,k);
        //这边先考虑两种特殊情况。这两种情况都是递归的终止条件。
        if(m==0)    //考虑A为空的情况
            return B[k-1];
        if(k==1)    //考虑K为1的情况
            return min(A[0],B[0]);
        int pa=min(k/2,m);    //这边还要考虑A数组长度不到k/2的情况
        int pb=k-pa;
        if(A[pa-1]<B[pb-1])
            findkth(A+pa,m-pa,B,n,k-pa);    //数组的递归常常用“数组名加位移距离，数组长度”来表示子数组
        else
            findkth(A,m,B+pb,n-pb,k-pb);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
         int k=(m+n)/2;
         if(2*k==m+n)   //中位数定义
            return (findkth(A,m,B,n,k)+findkth(A,m,B,n,k+1))/2;
         else
            return findkth(A,m,B,n,k+1);
    }
};
