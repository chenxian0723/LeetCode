###Problem
Given an index k, return the kth row of the Pascal's triangle.  
`For example, given k = 3,`  
`Return [1,3,3,1]. `

---

###Ideas
只需要输出pascal三角形的第n行，比前一题更加简单了。只使用一个数组，在双重循环中利用公式f[i]=f[i]+f[i-1]即可解决问题。
