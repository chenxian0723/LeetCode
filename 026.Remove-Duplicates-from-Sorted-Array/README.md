###Problem
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.  
Do not allocate extra space for another array, you must do this in place with constant memory.  
`For example,`  
`Given input array A = [1,1,2],`  
`Your function should return length = 2, and A is now [1,2].`  

---

###Ideas
这题也是使用两个下标，第一个下标i用来遍历数组，第二个下标j用来储存不相同的元素个数。  
如果A[i]和A[j]不相同的话，将A[j]赋值给A[i]，同时i和j各加一；否则就i++，j不变。
