class Solution {
public:
    int numTrees(int n) {
        if(n==0)
            return 1;
        int sum=0;
        for(int i=0;i<n;i++){                   
            sum+=numTrees(i)*numTrees(n-i-1);   //也可用迭代的方式，把每个numTrees值记录在一个数组中。
        }
        return sum;
    }
};
