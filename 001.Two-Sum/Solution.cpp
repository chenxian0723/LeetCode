class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> hm;
        int index1,index2;
        
        int num=numbers.size();
        for(int i=0;i<num;i++){
            if(hm.find(target-numbers[i])!=hm.end()){       //找到了，输出
                index1=hm[target-numbers[i]]+1;
                index2=i+1;
                if(index1<index2)
                    return {index1,index2};
                else
                    return {index2,index1};
            }
            else        //没找到，记录
                hm[numbers[i]]=i;
        }
    }
};
