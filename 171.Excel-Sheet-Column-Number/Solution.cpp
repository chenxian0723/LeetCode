class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){      //相当于26进制转换为10进制
            sum=sum*26+(s[i]-'A'+1);
        }
        return sum;
    }
};
