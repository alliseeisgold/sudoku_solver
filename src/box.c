#include "sudoku.h"

int boxSingles(Square*** sudoku, Box** boxes) {
    int i, j, x;
    int count, tmp;
    // loop through boxes
    for(i = 0; i < 9; i++) {
        //loop through possible array
        for(j = 0; j < 9; j++) {
            count = 0;
            //loop through squares
            for(x = 0; x < 9; x++) {
                if (boxes[i]->squares[x]->number != 0) {
                    continue;
                }
                if (boxes[i]->squares[x]->possible[j] == 0) {
                    tmp = x;
                    count++;
                }
                if (count == 2) {
                    break;
                }
            }
            if (count == 1) {
                boxes[i]->squares[tmp]->number = j + 1;
                UNSOLVED--;
                boxes[i]->squares[tmp]->solvable = 0;
                updateSudoku(sudoku, boxes[i]->squares[tmp]->row, boxes[i]->squares[tmp]->column);
            }
        } 
    }
}

Box** createBox() {
    int x, y;
    Box** boxes;
    boxes = malloc(sizeof(Box*) * 9);

    for (x = 0; x < 9; x++) {
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*) * 9);
        boxes[x]->numbers = 0;
        boxes[x]->solvable = 9;
        for (y = 0; y < 9; y++) {
            boxes[x]->possible[y] = 0;

        }
    }
    return boxes;
}

int updateBoxes(Square*** sudoku, int row, int column) {
    int x;
    int number = sudoku[row][column]->number;
    Box* box;
    box = sudoku[row][column]->box;

    for(x = 0; x < 9; x++) {
        if (box->squares[x]->possible[number - 1] == 0) {
            box->squares[x]->solvable--;
            box->squares[x]->possible[number - 1] = 1;
        }
    }
}

