#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;
int main() {
    int** puzzle;
    Sudoku* sudoku;
    puzzle = createPuzzle();
    sudoku = setUpPuzzle(puzzle);
    printPuzzle(sudoku->squares);
    printf("\n\n\n");
    checkPuzzle(sudoku->squares, sudoku->boxes);
    printPuzzle(sudoku->squares);
    return 0;
}