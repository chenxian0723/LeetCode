###Problem
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.  
You may assume no duplicates in the array.  
Here are few examples.  
`[1,3,5,6], 5 → 2`
`[1,3,5,6], 2 → 1`
`[1,3,5,6], 7 → 4`
`[1,3,5,6], 0 → 0`

---

###Ideas
如果把数组分成两段，则将两段中插入位置相加，发现刚好等于原数组的插入位置。  
因此这个问题可以用二分法解决。（关于数组查找问题好像大多数都是用二分法做）
