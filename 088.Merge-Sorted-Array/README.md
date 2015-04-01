###Problem
Given two sorted integer arrays A and B, merge B into A as one sorted array.  
`Note:`  
`You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively. `

---

###Ideas
有序数组的归并。数组和链表的区别就是链表不用移动数字，只需要更改连接顺序。  
为了使数字的移动次数尽可能少，可以从数组尾部开始排序。想到了这个，这题也就迎刃而解了。
