class Solution {
public:
    int maxSubArray(int A[], int n) {
        int mm=A[0];    //初始条件
        for(int i=1;i<n;i++){
            A[i]=max(A[i],A[i-1]+A[i]);   //转移方程，这里直接在原数组上修改能省去额外空间
            if(A[i]>mm)
                mm=A[i];
        }
        return mm;
    }
};
