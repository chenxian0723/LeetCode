class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0,last=0;
        int size=s.length();
        for(int i=0;i<size;i++){   //从头遍历
            if(s[i]!=' '){
                length++;
            }
            else{
                if(length!=0)       //考虑连续空格的情况
                    last=length;    //last上一个单词长度
                length=0;
            }
        }
        if(length>0)                //如果末尾不是空格，返回length
            return length;
        else                        //如果末尾是空格，返回last
            return last;
    }
};
