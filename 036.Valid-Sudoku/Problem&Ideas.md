###Problem
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.  
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.  
![example](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
A partially filled sudoku which is valid.  
`Note:`  
`A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.`  

---

###Ideas
没有巧妙办法，只能按行、列、九宫格依次进行判断。