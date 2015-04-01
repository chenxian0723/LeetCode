class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int length=digits.size();
        int carry=1;    //进位
        for(int i=length-1;i>=0;i--){
            int temp=digits[i];
            digits[i]=(temp+1)%10;
            carry=(temp+1)/10;
            if(carry==0)
                break;
        }
        if(carry==1)
            digits.insert(digits.begin(),1);    //前面插入1
        return digits;
    }
};
