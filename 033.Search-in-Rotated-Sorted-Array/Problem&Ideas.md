###Problem
Suppose a sorted array is rotated at some pivot unknown to you beforehand.  
`(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).`  
`You are given a target value to search. If found in the array return its index, otherwise return -1.`  
`You may assume no duplicate exists in the array.`  

---

###Ideas
这题其实就是二分查找的一个变种。收集了两种解题思路：
第一种思路：二分时可以判断出转动分割线是在那一边（和首元素比较即可）。因此可能会产生两种情况，一种是继续在一个较小的选择数组中二分查找，另一种是在一个正常的有序数组中二分查找。  
第二种思路：试图将数组恢复为有序（只需要将被旋转部分加上一个较大的数即可，将此步骤称为修正）。此时二分时直接和修正后的值比较（和首元素比较来判断是否需要修正）即可。
