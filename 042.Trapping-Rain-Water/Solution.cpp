class Solution {
public:
    int trap(int A[], int n) {
        int sum=0;    //记录总水量
        
        int left=0;
        int right=n-1;
        int lmax=A[left];   //lmax和rmax分别为左右边界
        int rmax=A[right];
        
        while(left<right){
            if(A[left]<A[right]){   //将较小的下标往中间移动
                if(A[left]<lmax)
                    sum+=lmax-A[left];
                else
                    lmax=A[left];
                left++;
            }
            else{
                if(A[right]<rmax)
                    sum+=rmax-A[right];
                else
                    rmax=A[right];
                right--;
            }
        }
        
        return sum;
    }
};
