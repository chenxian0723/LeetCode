###Problem
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

---

###Ideas
妈妈告诉我，最大子串和问题，要用动态规划解决啦～  
在每一位记录以当前位数字结尾的子串中最大的和，动态转移方程如下：  
`f(x)=max(a[x],f(x-1)+a[x]))`  
想出了转移方程就能很快地求解了，很典型的动规问题。  
（P.S. 动态规划的题目做多了会发现一个固有的套路，就是根据当前位置的多种情况来选择一个最优值）
