class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
            return 0;
        int max=0;
        int low=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<low)
                low=prices[i];      //low记录当前的最小值
            else if(prices[i]-low>max)
                max=prices[i]-low;  //max记录最大落差
        }
        return max;
    }
};
