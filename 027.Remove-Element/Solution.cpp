class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count=0;
        for(int i=0;i<n-count;i++){
            if(A[i]==elem){
                count++;
                A[i]=A[n-count];    //把最后的元素换上来
                i--;
            }
        }
        return n-count;
    }
};
