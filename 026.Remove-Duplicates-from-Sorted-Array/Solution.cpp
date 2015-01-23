class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2)   //处理一些特殊情况
            return n;
            
        int p=0;
        for(int i=1;i<n;i++){
            if(A[p]!=A[i])
                A[++p]=A[i];
        }
        
        return p+1;   //由于p是下标，p+1便是不同元素的个数
    }
};
