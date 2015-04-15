###Problem
Given a binary tree, return the inorder traversal of its nodes' values.  
`For example:`  
`Given binary tree {1,#,2,3},`  
`1`  
&#160;&#160;`\`  
&#160;&#160;&#160;&#160;`2`  
&#160;&#160;`/`  
`3`  
`return [1,3,2].`  
`Note: Recursive solution is trivial, could you do it iteratively?`

---

###Ideas
求先序遍历，用递归很容易实现。题目要求用迭代，用深度优先搜索可以实现，中序遍历的话每次弹出时输出即可。
