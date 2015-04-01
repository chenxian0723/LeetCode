class Solution {
public:
    int uniquePaths(int m, int n) {
        int p[100][100];
        for(int i=0;i<100;i++){   //初始化边界
            p[0][i]=1;
            p[i][0]=1;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                p[i][j]=p[i][j-1]+p[i-1][j];    //转移方程
        return p[m-1][n-1];
    }
};
