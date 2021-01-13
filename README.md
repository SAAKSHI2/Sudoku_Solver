# Sudoku_Solver
About the project : 

Sudoku is a logic-based number placement puzzle game. The objective is to fill a nine-by-nine (9x9) grid with digits (1-9) such that each row, column and 3x3 section contain number 1 to 9 without repetition.

This project is a Sudoku Solver that solves almost any sudoku puzzle. The user input a partially filled 9x9 sudoku, empty space in the grid is represented by 0 and the program gives the solved sudoku as output.
This project uses backtracking and recursion. 


Programming Language used : 
 C++


Functions in the program :

Input( ) : It asks the user to input the partially filled 9x9 grid. And store it in a 2-D array of row = 9 and column = 9.
 
 
Check_input( ) :  We pass grid in this function to check whether the input is a valid sudoku or not. 
 
 Invalid conditions :
 
    1.If the numbers entered in the partially filled sudoku is not in between 1 to 9.

    2.If input sudoku is completely filled.

    3.If the numbers in the input sudoku are repeated in the same row , column or submatrix (3x3).

If any of the above invalid conditions occur in input sudoku so the program will print an error message and will end ,else the further program for solving sudoku will be executed.


Check_num( )

 This function checks whether the number to be filled in the empty cell is safe or not, if yes then it will return true and will assign the number to the empty cell , else it will return false and will not assign that number.
 
 The function will check the following condition to place that number to empty cell :
 
         1. If that number is not present in the same row and in the same column.

         2.If that number is not present in the 3x3 submatrix.



Solve_sudoku( )

   -  This function is of bool type (will return true or false).
 
   - In this function we will pass input sudoku and row-column set to 0. And we will recursively call the function by increasing the column number till we get empty space (0)     in   the grid.
 
   - We keep a track of row and column. As column reaches 9 it is set to 0 and row number is increased.
 
   - As we find the empty space we will move ahead and will search for the number between 1 to 9 and check whether that number can be placed in that empty place or not by          calling  check_num( ) function.
 
   - If check_num( ) returns true then that number is assigned at that empty place and again the solve_sudoku( ) function is called recursively by increasing column number to     fill another empty space.
 
   - If check_num( ) returns false then the program will search for the other number and will again repeat the process until the function check_num( ) returns true.
 
   - If no number between 1 to 9 fits the empty space then the solve_sudoku( ) function will return false and this is backtracking. function will go back to previous empty       space   and will check for some other number between 1 to 9 that can fit there.
 
   - This whole process occurs recursively until the whole grid is filled and is solved. If even after the above processes some spaces are not filled ,no safe number is found     then the function returns false to the main function and will print the message of no solution found.
 
 
Print( ) : This print function will print the solved sudoku grid in the form of a 9x9 2D block.
 


How to run this project ?

Run this code in any IDE (integrated development environment) such as code::blocks , VS code , etc. with (.cpp) extension. As you run this code the output screen will ask you to enter the 9x9 grid (a partially filled valid sudoku grid in which space to be filled is represented by 0). As you enter the grid and press enter the output will be a solved sudoku. You can use this project to find a solution to any sudoku within a very less time and with zero effort.
