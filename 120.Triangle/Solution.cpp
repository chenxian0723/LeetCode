class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
        for(int j=n-2;j>=0;j--){
            for(int i=0;i<=j;i++){
                triangle[j][i]=triangle[j][i]+min(triangle[j+1][i],triangle[j+1][i+1]);   //转移方程
            }
        }
        return triangle[0][0];
    }
};
