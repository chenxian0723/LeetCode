class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1)   //第一格为障碍物的情况
            return 0;
        else
            obstacleGrid[m-1][n-1]=1;
        for(int i=m-2;i>=0;i--){        //初始化每行
            if(obstacleGrid[i][n-1]==1)
                obstacleGrid[i][n-1]=0;   //这边直接在原格子里记录，数组名较长显得代码较长
            else
                obstacleGrid[i][n-1]=obstacleGrid[i+1][n-1];
        }
        for(int i=n-2;i>=0;i--){      //初始化每列
            if(obstacleGrid[m-1][i]==1)
                obstacleGrid[m-1][i]=0;
            else
                obstacleGrid[m-1][i]=obstacleGrid[m-1][i+1];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j]=0;   
                else
                    obstacleGrid[i][j]=obstacleGrid[i+1][j]+obstacleGrid[i][j+1];
            }
        }
        return obstacleGrid[0][0];
    }
};
