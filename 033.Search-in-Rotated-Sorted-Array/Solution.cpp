class Solution {
public:
    int search(int A[], int n, int target) {
        int fix=10000;    //定义修正值
        int target2=target<A[0]?target+fix:target;    //首先修正目标值
        
        
        int low=0,high=n-1,mid,temp=0;
        while(low+1<high){    //常规的二分查找
            mid=(low+high)/2;
            temp=A[mid]<A[0]?A[mid]+fix:A[mid];   //修正A[mid]值
            if(temp==target2)
                break;
            else if(temp<target2)
                low=mid;
            else
                high=mid;
        }
        
        if(A[mid]==target)
            return mid;
        else if(A[low]==target)
            return low;
        else if(A[high]==target)
            return high;
        else
            return -1;
    }
};
