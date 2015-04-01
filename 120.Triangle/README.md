###Problem
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.  
`For example, given the following triangle`  
`[`  
&#160;&#160;&#160;&#160;     `[2],`  
&#160;&#160;&#160;    `[3,4],`  
&#160;&#160;   `[6,5,7],`  
&#160; ` [4,1,8,3]`  
`]`  
`The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).`  
`Note:`  
`Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. ` 

---

###Ideas
这是一个动态规划的题。记录到达每一个点的路径最小值即可。  
这题有两种记录方式，一种是bottom-top，另一种是top-bottom，显然无论从理解还是编程角度bottom-top更加简单。  
`f[m,n]=min(f[m+1,n],f[m+1,n+1])`（m为行数）
