class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.length();
        int n=b.length();
        if(m>n)
            return addBinary(b,a);    //保证b比a长
        int temp,carry=0;
        for(int i=m-1;i>=0;i--){
            temp=a[i]-'0'+b[i+n-m]-'0'+carry;   //模拟加法
            b[i+n-m]=temp%2+'0';
            carry=temp>>1;
        }
        for(int i=n-m-1;i>=0;i--){
            temp=b[i]-'0'+carry;
            b[i]=temp%2+'0';
            carry=temp>>1;
            if(carry==0)
                break;
        }
        if(carry)
            b="1"+b;    //前面补1
        return b;
    }
};
