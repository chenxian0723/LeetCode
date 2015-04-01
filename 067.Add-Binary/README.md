###Problem
Given two binary strings, return their sum (also a binary string).  
`For example,`  
`a = "11"`  
`b = "1"`  
`Return "100".`  

---

###Ideas
模拟二进制数的加法，这类题思路都是一样的（a+b+carry）。只不过这里用2代替10。  
除以2的时候尽量用位运算>>，速度比较快。（这个习惯要养成）  
