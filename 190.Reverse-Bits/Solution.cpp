class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int a=n&1;
        for(int i=0;i<31;i++){      //原数除去一位，新数左移后增加一位
            n=n>>1;       
            int temp=n&1;
            a=(a<<1)|temp;
        }
        return a;
    }
};
