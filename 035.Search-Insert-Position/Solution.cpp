class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(target<=A[0])    //比最小的小或者比最大的大
            return 0;
        if(target>A[n-1])
            return n;
        int mid=n/2;
        return searchInsert(A,mid,target)+searchInsert(A+mid,n-mid,target);
    }
};
