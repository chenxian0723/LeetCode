###Problme
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.  
`For example,`  
`Given 1->2->3->3->4->4->5, return 1->2->5.`  
`Given 1->1->1->2->3, return 2->3.`

---

###Ideas
这题与数组去重不一样的地方是，相同的元素会被全部删去（而不是保留一个）。  
初步想法是对于每一个元素，往后遍历，直到遇到不同的元素。也就是整个大循环里面还会有一个小的循环。
