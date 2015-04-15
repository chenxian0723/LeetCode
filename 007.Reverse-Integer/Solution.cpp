class Solution {
public:
    int reverse(int x) {
        int result=0;
        int d;
        while(x!=0){
            d=x%10;
            x=x/10;
            if((result>INT_MAX/10)||(result==INT_MAX/10)&&(d>7)         //越界的四种情况判断
            ||(result<INT_MIN/10)||(result==INT_MIN/10)&&(d<-8))
                return 0;
            result=result*10+d;
        }
        return result;
    }
};
