class Solution {
public:
    int majorityElement(vector<int> &num) {
        int major=num[0];
        int dis=1;      //记录当前最多数与其他数间的距离
        for(int i=1;i<num.size();i++){
            if(major==num[i])
                dis++;
            else{
                dis--;
                if(dis<0){
                    major=num[i];
                    dis=1;
                }
            }
        }
        return major;
    }
};
