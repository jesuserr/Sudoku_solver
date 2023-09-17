# Sudoku Solver

After learning backtracking concept during 42_Piscine I decided to write a program in C to solve any 9x9 Sudoku using this technique.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Installing

First of all, clone the repository on your computer

```
git clone https://github.com/jesuserr/Sudoku_solver.git
```

and then execute 'Make' inside the newly created ´Sudoku_solver' folder to compile the program

```
cd Sudoku_solver/ && make
```

## Execution

In order to run the program, execute it as shown below

```
./sudoku_solver .15.....2.....2.4..9....6.15.....4..42..3.9...634...8..86.25........3.6..4......8
```

The output should show the initial Sudoku and the solution found:

```
Initial Sudoku:
.15 ... ..2 
... ..2 .4. 
.9. ... 6.1 

5.. ... 4.. 
42. .3. 9.. 
.63 4.. .8. 

.86 .25 ... 
... ..3 .6. 
.4. ... ..8 

Solution Found:
815 364 792 
637 912 845 
294 578 631 

579 286 413 
428 731 956 
163 459 287 

986 125 374 
752 843 169 
341 697 528 
```

## Built With

* [Visual Studio Code](https://code.visualstudio.com/)

## Resources

* [Sudoku Generator for testing](https://qqwing.com/generate.html) - In 'Output format' choose the option 'One line' to obtain the Sudoku in proper format to feed the program.
* [Python Sudoku Solver - Computerphile](https://www.youtube.com/watch?v=G_UYXzGuqvM) - Video from Computerphile explaining backtracking algorithm to solve Sudoku in Python.
* [Solving Every Sudoku Puzzle](http://norvig.com/sudoku.html) - Essay from Peter Norvig dealing with Sudoku solving algorithms.
* [Backtracking - Wikipedia](https://en.wikipedia.org/wiki/Backtracking) - Wikipedia entry for Backtracking.

![Sudoku_solved_by_bactracking](https://github.com/jesuserr/Sudoku_solver/assets/118769872/2d404260-0184-4ec8-a5b2-1dbde28feb9c)
