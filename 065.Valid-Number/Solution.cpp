class Solution {
public:
    
    string removeSpace(string s){
        int head=0;
        int tail=s.length()-1;
        while(true){
            if(s[head]==' ')
                head++;
            else if(s[tail]==' ')
                tail--;
            else
                break;
        }
        return s.substr(head,tail-head+1);
    }

    bool isNumber(string s) {
        int pos=0;
        bool hasE=false;      //记录有没有'e'
        bool hasDot=false;    //记录有没有'.'
        bool hasNum=false;    //记录有没有数组
        s=removeSpace(s);     //移除首位的空格
        if((s[pos]=='-')||(s[pos]=='+'))      //去符号
            pos++;
        for(int i=pos;i<s.length();i++){
            if((s[i]-'0'>=0)&&(s[i]-'0'<=9)){       //是数字，则继续循环
                hasNum=true;
                continue;
            }
            if((s[i]=='.')&&(!hasDot)){             //字符是，满足条件：第一次出现
                hasDot=true;
                continue;
            }
            if((s[i]=='e')&&(!hasE)&&(hasNum)){     //字符是'e'，满足几个条件：第一次出现，已经有数字出现
                hasE=true;
                hasDot=true;          //小数点不能再出现了
                hasNum=false;         //数字必须再次出现
                if((s[i+1]=='-')||(s[i+1]=='+'))    //'e'后面可能跟有符号
                    i++;
                continue;
            }
            return false;
        }
        if(hasNum)                    //有数字出现，无论是e前，还是e后（.后可以没有数字）
            return true;
        else
            return false;
    }
};
