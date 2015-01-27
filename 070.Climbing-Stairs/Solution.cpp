class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2)
            return n;
            
        int a[100];     //设定初值
        a[0]=0;
        a[1]=1;
        a[2]=2;
        
        for(int i=3;i<=n;i++)     //循环计算
            a[i]=a[i-1]+a[i-2];
            
        return a[n];
    }
};
