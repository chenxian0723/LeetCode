###Problem
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.  
`For example,`   
`Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.`  
![example](http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png)  
`The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!`  

---

###Ideas
数组类型的应用题。其实想一想就会发现，最高的那个柱子至关重要，知道了最高的柱子下标x后，就能分别从0～x和x～n-1逐个计算水量。当然如果最高值有多个的时候，任取其中一个即可（即数组的一个极大值）。  
计算积水量的方法为：取A[i]为左侧边界，若下一个数小于A[i]，则积水量为A[i]-A[i+1]。直到找到比左侧边界更大的值A[j]，此时将A[j]设为新的左侧边界。右侧区域积水量的计算是一个类似的过程，只不过下标会不断减小。  

但直觉告诉我，这种要先遍历一遍的方法绝对不会是最佳方法。  
因为计算的时候需要左右两边分开算，因此可以考虑从两端向中间进行遍历。具体算法如下：  
1.初始状态p1＝0，p2＝n-1。  
2.比较A[p1]和A[p2]，将较小的一端（相同则任意一端）向中间移动一格，并计算积水量。  
3.重复第二步，直到p1与p2相等为止。（其实不难理解，这个相等的值，一定是数组的极大值）


