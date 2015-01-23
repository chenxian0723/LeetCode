###Problem
Given a linked list, remove the nth node from the end of list and return its head.  
`For example,`  
`Given linked list: 1->2->3->4->5, and n = 2.`  
`After removing the second node from the end, the linked list becomes 1->2->3->5.`  
Note:  
`Given n will always be valid.  `
`Try to do this in one pass.  `

---

#Ideas
题中倒数第n个，这里的n可以看成是待删除元素到链表末尾的距离。容易想到的一种方法是：  
1.定义两个指针，并让前指针（其中一个指针）先移动n个单位。  
2.然后同时移动两个指针，直到前指针移动到链表末尾，此时后指针应该指向待删除元素的前一个元素。  
3.接下来删除对应元素即可。  
  
Tips: 链表题目还是应该使用链表的方法，避免使用数组的思维解题。（感谢好心人的提醒）
