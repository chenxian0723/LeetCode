###Problem
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.  
`Note: You can only move either down or right at any point in time.`

---

###Ideas
和最短路径法有点相似，还是使用动态规划解决。  
记录上边和左边的最小值，然后加上自身，就是局部最优情况。  
状态转移方程：  
`f[m][n]=min(f[m-1][n],f[m][n-1])+f[m][n];`
根据转移方程求解即可。
