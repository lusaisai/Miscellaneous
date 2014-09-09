/* 
 * File:   board.h
 * Author: lusaisai
 *
 * Created on September 10, 2014, 4:13 AM
 */

#ifndef BOARD_H
#define	BOARD_H

namespace NQueens {
    class Position {
        friend class Board;
    
        public:
            Position(unsigned int x, unsigned int y);
        private:
            unsigned int x;
            unsigned int y;
    };
    
    class Board {
    public:
        Board(unsigned int size);
        ~Board();
        bool place(Position p);
        bool remove(Position p);
        void print();
        unsigned int getSize();
    private:
        unsigned int size;
        bool **data;
        bool issafe(Position p);
        void init_board();
    };

} 


#endif	/* BOARD_H */

