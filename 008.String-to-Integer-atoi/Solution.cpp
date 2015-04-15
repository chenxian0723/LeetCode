class Solution {
public:
    int myAtoi(string str) {
        int pos=0;
        int sign=1;
        while(str[pos]==' '){     //去空格
            pos++;
        }
        if(str[pos]=='-'){        //判断正负
            sign=-1;
            pos++;
        }
        else if(str[pos]=='+')
            pos++;
        int sum=0;
        bool overflow=false;
        while((pos!=str.length())&&(str[pos]-'0'<=9)&&(str[pos]-'0'>=0)){
            if((sum<INT_MAX/10)||
            (sum==INT_MAX/10)&&((str[pos]<='7')||(str[pos]=='8')&&(sign==-1))){   //判断是否溢出
                sum=sum*10+str[pos]-'0';
                pos++;
            }
            else{
                overflow=true;
                break;
            }
        }
        if(overflow)
            return sign>0?INT_MAX:INT_MIN;
        sum*=sign;
        return sum;
    }
};
