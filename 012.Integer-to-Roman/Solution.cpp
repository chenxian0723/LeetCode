class Solution {
public:
    string intToRoman(int num) {
        string res;
        int digit=0;
        int wei=1;
        while(num>0){   //从低位到高位依次转换
            digit=num%10;
            num/=10;
            if(digit!=0)
                res=digitToRoman(digit,wei)+res;    //转换的时候记录一下位数
            wei++;
        }
        return res;
    }
    
    string digitToRoman(int digit,int wei){
        string one,five,ten,roman;
        switch(wei){
            case 1:
                one="I";
                five="V";
                ten="X";
                break;
            case 2:
                one="X";
                five="L";
                ten="C";
                break;
            case 3:
                one="C";
                five="D";
                ten="M";
                break;
            case 4:
                one="M";
                break;
        }
        switch(digit){    //拼接规则，不知道是不是可以优化
            case 3:
                roman+=one;
            case 2:
                roman+=one;
            case 1:
                roman+=one;
                break;
            case 4:
                roman+=one;
            case 5:
                roman+=five;
                break;
            case 8:
                roman=five+one+one+one;
                break;
            case 7:
                roman=five+one+one;
                break;
            case 6:
                roman=five+one;
                break;
            case 9:
                roman=one+ten;
                break;
        }
        return roman;
    }
};
