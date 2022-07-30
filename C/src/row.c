#include "sudoku.h"

int checkRows(Square*** sudoku, Box** boxes) {
    int i, j, x;
    int sum[9];
    int place[9];
    // loop through all rows
    for(i = 0; i < SIZE_ROWS; i++) {
        // initialize sum to 0
        for (j = 0; j < SIZE_COLUMNS; j++) {
            place[j] = 0;
            sum[j] = 0;
        }
        // loop through each square in the row
        for(j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->number != 0) {
                continue;
            }
            // loop through all possibilities
            for (x = 0; x < SIZE_COLUMNS; x++) {
                // checks if number (x) is possible
                if (sudoku[i][j]->possible[x] == 0) {
                    sum[x]++;
                    place[x] = j;
                }
            }
        }
        for (j = 0; j < SIZE_COLUMNS; j++) {
            if (sum[j] == 1 ) {
                sudoku[i][place[j]]->number = j + 1;
                sudoku[i][place[j]]->solvable = 0;
                UNSOLVED--;
                updateSudoku(sudoku, i, place[j]);
                updateBoxes(sudoku, i, place[j]);
                return 1;
            }
        }
    }
    return 0;
}