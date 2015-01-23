###Problem
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.  
For example, given array S = {-1 2 1 -4}, and target = 1.  
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). 

---

###Ideas
类似与Two Sum的题。Two Sum考察的是复杂度，并要求返回数字的下标，而此题只需要返回Sum值，因此想到的一点是可以打乱数组次序（也就是可以先排序）。  
将其中一个值进行遍历，便能将问题转换为Two Sum Closest了。接下来用首尾指针逼近目标值就可以了：  
1.i指向第一个数，j指向最后一个数  
2.如果两数之和大于目标值，j前移。  
3.如果两数之和小于目标值，i后移。  
4.重复第2，3步，直至i不小于j。  
当然由于题目是closest，需要记录一下距离，判断的时候多加几个步骤即可。
