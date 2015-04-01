###Problem
Given an array and a value, remove all instances of that value in place and return the new length.  
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

---

###Ideas
顺序遍历，遇到相等元素删除，由于可以交换数组元素的顺序，因此为了减少移动次数，删除元素后把最后的元素移上来即可。
