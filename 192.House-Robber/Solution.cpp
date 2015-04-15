class Solution {
public:
    int rob(vector<int> &num) {
        int size=num.size();
        if(size==0)
            return 0;
        else if(size==1)
            return num[0];
        else if(size==2)
            return max(num[0],num[1]);
        int total[size];
        total[0]=num[0];
        total[1]=max(num[0],num[1]);
        for(int i=2;i<size;i++){
            total[i]=max(num[i]+total[i-2],total[i-1]);     //抢或不抢，钱都在那里
        }
        return total[size-1];
    }
};
