###Problem
Given a non-negative number represented as an array of digits, plus one to the number.  
The digits are stored such that the most significant digit is at the head of the list.

---

###Ideas
模拟数的加法运算，这个比字符串模拟更加简单。  
从低位相加即可，遇到进位就记录下来，直到没有进位。如果最后有进位，则在前面插入1。
