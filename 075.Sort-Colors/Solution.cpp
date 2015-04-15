class Solution {
public:
    void sortColors(int A[], int n) {
        int low=0,high=n-1;
        int i=0;
        while(i<=high){         //使用快排partition函数的思想，把1作为比较值，小的和前面交换，大的和后面交换
            if(A[i]==0){
                swap(A[i],A[low]);
                low++;          //low记录头部交换位置
                i++;            //i是当前需要比较的值
            }
            else if(A[i]==2){
                swap(A[i],A[high]);
                high--;         //hign记录尾部交换位置，high后面的都是2，因此不用再比较
            }
            else
                i++;
        }
        return;
    }
};
