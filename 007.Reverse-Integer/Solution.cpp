class Solution {
public:
    int reverse(int x) {
        long long ans=0;    //为了方便在过程中记录真实数据
        int d;
        
        while(x!=0){
            d=x%10;
            x=x/10;
            ans=ans*10+d;
        }
        
        if((ans>2147483647)||(ans<-2147483648))   //越界判断
            ans=0;
        return (int)ans;
    }
};
