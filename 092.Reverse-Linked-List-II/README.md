###Problem
Reverse a linked list from position m to n. Do it in-place and in one-pass.  
`For example:`  
`Given 1->2->3->4->5->NULL, m = 2 and n = 4,`  
`return 1->4->3->2->5->NULL.`  
`Note:`  
`Given m, n satisfy the following condition:`  
`1 ≤ m ≤ n ≤ length of list.`

---

###Ideas
将链表的部分倒转。有两种方法：  
第一种：头插法，将需要倒转的部分依次插入特定节点前面即可。  
第二种：反转指针，将原先的next指针依次反转。  
个人还是比较欣赏第一种。
