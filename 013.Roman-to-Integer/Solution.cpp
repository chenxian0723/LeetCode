class Solution {
public:
    int romanToInt(string s) {
        int right=1;
        int sum=0;
        for(int i=s.length()-1;i>=0;i--){
            int temp=romandigit(s[i]);
            if(temp<right)
                sum-=temp;
            else 
                sum+=temp;
            right=temp;
        }
        return sum;
    }
    
    int romandigit(char c){   //字母和数字的转换
        int digit=0;
        switch(c){
            case 'I':
                digit=1;
                break;
            case 'V':
                digit=5;
                break;
            case 'X':
                digit=10;
                break;
            case 'L':
                digit=50;
                break;
            case 'C':
                digit=100;
                break;
            case 'D':
                digit=500;
                break;
            case 'M':
                digit=1000;
                break;
        }
        return digit;
    }
};
