class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> hm;
        int index1,index2;
        
        int num=numbers.size();
        for(int i=0;i<num;i++){     //构建map
            if(hm.find(target-numbers[i])!=hm.end()){     //这里如果有相同的值，只需记录一个，除非这两个数加起来刚好等于目标值
                if(2*numbers[i]==target)
                    return {hm[target-numbers[i]]+1,i+1};
            }
            else
                hm[numbers[i]]=i;
        }
        
        for(int i=0;i<num;i++){     //遍历数组，寻找是否存在特定数
            if(2*numbers[i]==target)    //为了防止在map中找到的数就是自身，因此直接跳过
                continue;
            if(hm.find(target-numbers[i])!=hm.end()){
                index1=i+1;
                index2=hm[target-numbers[i]]+1;
                break;
            }
        }
        
        if(index1<index2)     //按大小顺序返回
            return {index1,index2};
        else
            return {index2,index1};
    }
};
