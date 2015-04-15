class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0){
            if(n&1)   //位运算简化复杂度
                count++;
            n=n>>1;
        }
        return count;
    }
};
