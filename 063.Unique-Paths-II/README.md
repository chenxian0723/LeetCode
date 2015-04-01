###Problem
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.  
[  
  [0,0,0],  
  [0,1,0],  
  [0,0,0]  
]  
The total number of unique paths is 2.

Note: m and n will be at most 100.

---

###Ideas
在格子中增加了障碍物，大致思路还是一样，用动态规划求解。  
遇到障碍物，路径条数就直接设为0，会不会有问题？好像没有问题呢，那就这样求解。  
注意边界值的设定，如果一条边中间有障碍物，那么其后面格子的值应该都设为0。  
