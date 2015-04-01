###Problem
Given a roman numeral, convert it to an integer.  
Input is guaranteed to be within the range from 1 to 3999.

---

###Ideas
int和罗马数字之间的转换。  
罗马数字转换成int。虽然知道罗马数字的写法，但一开始还是没有头绪。后来百度搜了一下罗马数字，看到一个说法是：罗马数字里用到的都是加法。于是产生了一些灵感，具体转换过程如下：  
1.从低位到高位转换。  
2.如果左边的数字比右边小，那就减去，否则就加上。  

