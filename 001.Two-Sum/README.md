###Problem
Given an array of integers, find two numbers such that they add up to a specific target number.  
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.  
You may assume that each input would have exactly one solution.  
`Input: numbers={2, 7, 11, 15}, target=9`  
`Output: index1=1, index2=2`  

----

###Ideas
常规方法使用双重循环肯定会超时，因此我们应该试图降低时间复杂度。  
很多人都会想到哈希，因此我们就使用map来完成这个题，想到了使用map后这个题就没什么难点了。
