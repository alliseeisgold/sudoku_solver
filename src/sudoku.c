#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main() {
    int** puzzle;
    int progress;
    Sudoku* sudoku;
    puzzle = createPuzzle();
    sudoku = setUpPuzzle(puzzle);
    printf("Your puzzle:\n");
    printPuzzle(sudoku->squares);
    while (UNSOLVED > 0) {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);
        if (progress == 0) {
            printf("\nFailed to solve the puzzle!\n\n");
            return 0;
        }
    }
    printf("Solved!\n\n");
    printPuzzle(sudoku->squares);
    return 0;
}