class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size=prices.size();
        if(size<=1)
            return 0;
        int a[size],b[size];
        a[0]=0;
        b[size-1]=0;
        int low=prices[0];
        for(int i=1;i<size;i++){    //从头到尾，记录到某一天能获得的最大利润
            if(prices[i]<low){
                low=prices[i];
                a[i]=a[i-1];
            }
            else{
                a[i]=max(prices[i]-low,a[i-1]);
            }
        }
        int high=prices[size-1];
        for(int i=size-2;i>=0;i--){    //从尾到头，记录某一天到最后一天能获得的最大利润
            if(prices[i]>high){
                high=prices[i];
                b[i]=b[i+1];
            }
            else{
                b[i]=max(high-prices[i],b[i+1]);
            }
        }
        int maxPro=0;
        for(int i=0;i<size;i++){        //两边利润相加求最大值
            maxPro=max(maxPro,a[i]+b[i]);
        }
        return maxPro;
    }
};
