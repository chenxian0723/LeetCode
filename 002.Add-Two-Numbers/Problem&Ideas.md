###Problem
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.  
`**Input**: (2 -> 4 -> 3) + (5 -> 6 -> 4)  `
`**Output**: 7 -> 0 -> 8  `

---

###Ideas
这题思路比较简洁，就是模拟加法的过程，使用一个标志来记录是否进位即可。  
代码写法上有两个小的分支：  
1.其中一个链表遍历完时，再单独遍历另外一个（此时还是要注意进位）。  
2.将遍历完的链表后面补上0，这样便能保证两个链表遍历结束。  
