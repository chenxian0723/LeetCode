###Problem
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.  
`For example:`  
`Given the below binary tree and sum = 22,`  
&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;`5`  
&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;`/`&#160;&#160;`\`  
&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;`4`&#160;&#160;&#160;&#160;&#160;`8`  
&#160;&#160;&#160;&#160;&#160;&#160;`/`&#160;&#160;&#160;&#160;&#160;`/`&#160;&#160;`\`  
&#160;&#160;&#160;&#160;`11`&#160;&#160;&#160;&#160;`13`&#160;&#160;&#160;&#160;`4`  
&#160;&#160;`/`&#160;&#160;`\`&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;`\`  
`7`&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;`2`&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;`1`  
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

---

###Ideas
判断从根节点到叶子节点的路径和是否等于特定值。将目标值减去当前节点值后分别对左右子树进行递归。终止条件是子节点的数值刚好等于目标值。
