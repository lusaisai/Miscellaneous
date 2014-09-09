/* 
 * File:   main.cpp
 * Author: lusaisai
 *
 * Created on September 10, 2014, 4:11 AM
 */

#include <cstdlib>
#include "board.h"

using namespace NQueens;

bool place_row(Board& board, int row) {
    if ( row >= board.getSize() ) return true; // end
    
    for( int column = 0; column < board.getSize(); column++ ) {
        if ( board.place(Position(row, column)) ) { // place a queen, go to next row if success
//            board.print();
            if ( ! place_row(board, row+1) ) {
                board.remove(Position(row, column)); // remove queen if next row fails
//                board.print();
            } else {
                return true;
            }
        } 
    }
    
    return false;
}

void place_queens(Board& board) {
    place_row(board, 0);
}

/*
 * 
 */
int main(int argc, char** argv) {
    Board b(4);
    place_queens(b);
    b.print();
    
    Board c(8);
    place_queens(c);
    c.print();
    
    return 0;
}

