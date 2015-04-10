###综述
容器类是C++编程的一大特色。容器的加入使得编程的效率得到了极大的提升。  
在C++中，用到的容器可以分为以下几类：  
1.顺序类容器  
`vector（数组）`  
`deque（双向队列）`  
`list（双向链表）`  
2.容器适配器  
`stack（栈）`  
`queue（队列）`  
`priority_queue（优先队列）`  
3.关联类容器  
`set/multiset（集合）`  
`map/multimap（映射）`  
`unordered_set/unordered_multiset（无序集合）`  
`unordered_map/unordered_multimap（无序映射）`  

----

###
常规方法使用双重循环肯定会超时，因此我们应该试图降低时间复杂度。  
很多人都会想到哈希，因此我们就使用map来完成这个题，想到了使用map后这个题就没什么难点了。

