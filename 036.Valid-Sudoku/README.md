###Problem
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.  
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.  
![example](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
A partially filled sudoku which is valid.  
`Note:`  
`A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.`  

---

###Ideas
整体思路没有巧妙办法，只能按行、列、九宫格依次进行判断。  
但是判断是否有重复有几种可选的方法：  
第一种：直接使用set，容易想到，写起来也比较方便。  
第二种：由于数字1-9与数组下标0-8刚好是一一对应的，因为可以将读到的数与对应位置上比较，如果不同则填入，相同则说明有重复。  
第三种：按位操作的思想，数字是n，就在其后加n个0（向左移动n位），最后所有数相加后每一位都不大于1，说明数字没有重复。
