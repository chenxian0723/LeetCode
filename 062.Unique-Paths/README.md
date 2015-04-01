###Problem
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).  
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).  
How many possible unique paths are there?  
`Note: m and n will be at most 100.`

---

###Ideas
动态规划题目。  
到每一个格子的走法有两种情况，一是从上面那格走下来，二是从左边那格走过来。  
因此转移方程也就出来了：  
`f[m][n]=f[m-1][n]+f[m][n-1]`  
最后注意一下初始条件就可以了，就是最边上的格子都只有1种走法，初始化为1。
