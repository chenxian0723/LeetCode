###Problem
Determine whether an integer is a palindrome. Do this without extra space.  

---

###Ideas
判断一个数是不是回文数。然后原题给了一点要求（不使用额外空间）。首先来想一下如果使用额外空间怎么解，字符串方式可以解决，但是也挺麻烦。  
最通用的应该还是反转int，然后与原数进行比较。考虑几个情况，为负数时返回false，反转时溢出怎么办？真正的回文数是不可能溢出的，一旦溢出后值肯定也不会和原来的相等（应该不会吧？），因此溢出问题不考虑好像也没事。

