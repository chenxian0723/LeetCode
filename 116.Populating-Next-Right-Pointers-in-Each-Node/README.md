###Problem
Given a binary tree  
    `struct TreeLinkNode {`  
&#160;&#160;&#160;&#160;`TreeLinkNode *left;`  
&#160;&#160;&#160;&#160;`TreeLinkNode *right;`  
&#160;&#160;&#160;&#160;`TreeLinkNode *next;`  
    `}`  
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.  
Initially, all next pointers are set to NULL.  
`Note:`  
`You may only use constant extra space.`  
`You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).`   

---

###Ideas
题目规定了树是一棵完全二叉树，因此就不需要考虑左右子树是否存在的问题了。  
根据题意，很显然，左子树的next指针一定是指向右子树的。右子树的next指针分两种情况：一是指向父节点的next的左子树，二是指向null。（画一个图就能看得更加清楚了）
