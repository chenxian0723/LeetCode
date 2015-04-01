class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int mm=m-1;   //mm和nn记录A和B的当前位置
        int nn=n-1;
        for(int i=m+n-1;i>=0;i--){
            if((mm<0)||(nn<0))
                break;
            if(A[mm]<B[nn]){
                A[i]=B[nn];
                nn--;
            }
            else{
                A[i]=A[mm];
                mm--;
            }
        }
        if(mm<0){
            for(int i=0;i<=nn;i++)    //将B剩余部分拷贝到A
                A[i]=B[i];
        }
    }
};
