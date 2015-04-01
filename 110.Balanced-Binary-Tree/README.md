###Problem
Given a binary tree, determine if it is height-balanced.  
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

---

###Ideas
递归判断每个子树是否为平衡二叉树。需要注意的是如果左右子树都是平衡二叉树，此时并不能保证改树是平衡的，因为还有一个条件就是左子树深度和右子树深度差不超过1。  
因此我们在递归判断的时候还必须要能够得到左右子树的深度。这里有两个返回值，一个是bool类型，一个是int类型。如何做到呢？  
一个简单的方法就是把树的深度作为一个引用传入，在判断是否为平衡二叉树的时候更改这个深度值。  
知道思路就可以尝试写代码了，由于把引用作为返回值的写法平时写得不多，写起来也不怎么确定，还需要多注意。
