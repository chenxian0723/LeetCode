class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res=0;
        int dis=10000;    //设定一个最大距离
        
        sort(num.begin(),num.end());    //对数组排序
        
        int n=num.size();
        int j,k;    //可移动的首位下标
        for(int i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            while(j<k){   //不断移动j和k
                int temp=num[i]+num[j]+num[k]-target;
                if(temp>0){
                    k=k-1;
                    if(temp<dis){
                        dis=temp;
                        res=temp+target;
                    }
                }
                else{
                    j=j+1;
                    if(-temp<dis){
                        dis=-temp;
                        res=temp+target;
                    }
                }
            }
        }
        
        return res;
    }
};
