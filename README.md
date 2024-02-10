# Algorithms
## Task 1
Inverting a Coin Triangle Consider an equilateral triangle formed by closely packed pennies or other identical coins like the one shown in the figure below. (The centers of the coins are assumed to be at the points of the equilateral triangular lattice.)
Use iterative improvement method to design an algorithm to flip the triangle upside down in the minimum number of moves if on each move you can slide one coin at a time to its new position.
## Task 2
Consider the one-dimensional version of peg solitaire played on an array of n cells, where n is even and greater than 2. Initially, all but one cell are occupied by some counters (pegs), one peg per cell. On each move, a peg jumps over its immediate neighbor to the left or to the right to land on an empty cell; after the jump, the jumped-over neighbor is removed from the board.
Using divide and conquer methodology to
- write an algorithm that remove all but one peg by a sequence of such moves.
- Find all the locations of the empty cell in the initial setup for which the puzzle can be solved and the corresponding locations of the single remaining peg.
## Task 3
There are six knights on a 3 × 4 chessboard: the three white knights are at the bottom row, and the three black knights are at the top row.
Design an iterative improvement algorithm to exchange the knights to get the position shown on the right of the figure in the minimum number of knights moves, not allowing more than one knight on a square at any time.
## Task 4
There is a row of n security switches protecting a military installation entrance. The switches can be manipulated as follows:
1. The rightmost switch may be turned on or off at will.
1. Any other switch may be turned on or off only if the switch to its immediate right is on and all the other switches to its right, if any, are off.
1. Only one switch may be toggled at a time.
Design a Dynamic Programing algorithm to turn off all the switches, which are initially all on, in the minimum number of moves. (Toggling one switch is considered one move.) Also find the minimum number of moves.
## Task 5
There are eight disks of different sizes and four pegs. Initially, all the disks are on the first peg in order of size, the largest on the bottom and the smallest on the top.
Use dynamic programming method to transfer all the disks to another peg by a sequence of moves. Only one disk can be moved at a time, and it is forbidden to place a larger disk on top of a smaller one.
<br>
Does the divide and conquer algorithm can solve the puzzle in 33 moves? If not then design an algorithm that solves the puzzle in 33 moves.
