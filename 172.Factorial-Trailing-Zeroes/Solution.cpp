class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n>=5){      //只需求出因子中5的个数
            int temp=n/5;
            count+=temp;
            n=temp;
        }
        return count;
    }
};
