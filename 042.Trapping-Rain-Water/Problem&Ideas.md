###Problem
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.  
`For example,`   
`Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.`  
![example](http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png)  
`The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!`  

---

###Ideas
数组类型的应用题。其实想一想就会发现，最高的那个柱子至关重要，知道了最高的柱子下标x后，就能分别从0～x和x～n-1逐个计算水量。当然如果最高值有两个x，y的时候，情况又有所不同（不过也不难，分别计算0～x，x～y，y～n-1）。但直觉告诉我，这种要先遍历一遍的方法绝对不会是最佳方法。  


