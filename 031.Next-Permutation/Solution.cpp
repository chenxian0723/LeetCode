class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size=num.size();
        if(size==1)
            return;
        int p1=size-2;
        while((p1>=0)&&(num[p1]>=num[p1+1]))    //找到要改变的最低位
            p1--;
        if(p1>=0){
            int p2=size-1;
            while(num[p1]>=num[p2])     //找到改变位的下一个数
                p2--;
            swap(num[p1],num[p2]);      //交换两者
        }
        for(int i=p1+1;i<=size-1;){     //颠倒后面的顺序，即从小到大排
            swap(num[i],num[size-1]);
            i++;
            size--;
        }
        return;
    }
};
