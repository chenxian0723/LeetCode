class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0)
            return 0;
        int profit=0;
        int low=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]>low){
                profit=prices[i]-low+profit;    //每有一次利润就累加
                low=prices[i];                  //表示一个新交易后，当前价格为最低点
            }
            else
                low=prices[i];                  //表示没有交易，但是产生了新的最低点
            //其实可以把上升的一段过程作为一次买卖，那样就不用每天累加
        }
        return profit;
    }
};
