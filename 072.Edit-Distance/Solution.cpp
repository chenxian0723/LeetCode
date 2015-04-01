class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int ed[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0)    //初始化
                    ed[i][j]=j;
                else if(j==0)   //初始化
                    ed[i][j]=i;
                else{
                    int temp=min(ed[i-1][j]+1,ed[i][j-1]+1);    //min只支持2个数字，因此先求出插入和删除的较小值
                    if (word1[i-1]==word2[j-1])
                        ed[i][j]=min(temp,ed[i-1][j-1]);        //状态转移方程
                    else
                        ed[i][j]=min(temp,ed[i-1][j-1]+1);      //状态转移方程
                }
            }
        }
        return ed[m][n];
    }
};
