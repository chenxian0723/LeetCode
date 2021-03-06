###Problem
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)). 

---

###Ideas
要对两个数组求中位数，而且题目提示了复杂度为O(log (m+n))，一般人肯定先想到用二分的方法。  
我最先想到的二分法如下：  
1.先分别求两个数组的中位数m和n，然后比较他们的大小（假设m>n）。  
2.根据中位数的性质，可以确定中位数肯定在A[0~m]和B[n~sizeB]之间。  
3.然后就在排除的2个区域内去掉相等长度的数组（根据A和B的长度决定）。  
4.接下来就是递归上面的过程，直到最后得到中位数。  
用这个思路开始写代码后，我发现每一步都是特别多的问题要考虑。  
第一步中求中位数涉及到数组长度奇偶问题，我是用/2计算的,不考虑奇偶对二分的关系不大。  
第二步和第三步去除数组时，问题就出现了。到后来总会出现无法再去除的现象，于是我把去除的开区间改成闭区间，在特殊情况下结果都不对了。  
最麻烦的还是第四步，怎么判断他的终止条件。开始考虑的不多，后来提交代码后发现情况太多了，最后不得不放弃这种方法。  

最后，只能去网上找解决方法。网上使用的都是findkth()的思路，在两个有序的数组中找到第k大的数。当然方法也是递归，只不过是在每个数组中找k/2的位置进行比较，然后去除较小的前面部分。大致思路如下：  
1.在每个数组中找k/2的位置进行比较（假设A[k/2]>B[k/2]）。  
2.删除B数组0~k/2部分，然后将k也减去删除部分的长度。  
3.递归上面的过程，直到找到k对应的数。  
这个过程虽然知道了，但也不好写，因为要考虑的条件还是比较多的。例如当k/2大于数组长度时，当k==1时等等。  

总之，这个题我觉得是相当难的。如果没有看到过findkth()这种方法，估计很难想出来，名副其实的hard题。
