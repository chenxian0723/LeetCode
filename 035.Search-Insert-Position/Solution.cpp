class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n==1)    //终止条件
            if(target<=A[0])
                return 0;
            else
                return 1;
        int mid=n/2;
        return searchInsert(A,mid,target)+searchInsert(A+mid,n-mid,target);
    }
};
