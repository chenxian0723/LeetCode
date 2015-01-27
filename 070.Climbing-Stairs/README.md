###Problem
You are climbing a stair case. It takes n steps to reach to the top.  
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?  

---

###Ideas
其实就是一个斐波那契数列，首先想到的是用递归的方法。但在实际过程中，发现使用递归会报超时错误，后来就改用循环。  
（这题给了我一个启示，虽然从想法上来说，递归比单纯的循环应该更好，但却没有循环来得搞笑，后来我也在网上看到了一些说法，递归省空间，但是每一步都得重新计算，非常费时，而循环的话能够将计算过的值存储下来，虽然牺牲了少量空间，却大大提高了效率）
