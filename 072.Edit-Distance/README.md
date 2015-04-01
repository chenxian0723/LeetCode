###Problem
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)  
You have the following 3 operations permitted on a word:  
`a) Insert a character`  
`b) Delete a character`  
`c) Replace a character`   

---

###Ideas
编辑距离，是信息检索课上的一个概念，用来描述两个单词相差得多远。题目说了，有3种方式可以来改变一个单词，插入/删除/更改，从一个单词到另一个单词所需的步数就是编辑距离。这题要求的是两个单词的最小编辑距离。  
求编辑距离有一种经典的算法，当然其本质就是动态规划。具体思路为：  
根据两个单词当前位置（假设为A[m]和B[n]）的字符是否相同有如下几种情况：  
1.相同。`f(m,n)=min(f(m-1,n)+1,f(m,n-1)+1,f(m-1,n-1))`  
2.不同。`f(m,n)=min(f(m-1,n)+1,f(m,n-1)+1,f(m-1,n-1)+1)`  
其中  
`f(m-1,n)+1代表从A增加了一个字符变成B`  
`f(m,n-1)+1代表从A删除了一个字符变成B`  
`f(m-1,n-1)+1代表从A替换了一个字符变成B`  
这个逻辑得理清楚才能求出编辑距离，而且即使相等的时候，也必须是从3个距离里面求最小值，而不是直接使用f(m-1,n-1)。  
