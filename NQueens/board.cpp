#include "board.h"
#include <iostream>

namespace NQueens {

    Position::Position(unsigned int x, unsigned int y) {
        this->x = x;
        this->y = y;
    }
    
    Board::Board(unsigned int size) {
        this->size = size;
        this->data = new bool*[size];
        for( int i = 0; i < size; i++ ) {
            this->data[i] = new bool[size];
        }
        init_board();
    }
    
    Board::~Board() {
        for( int i = 0; i < size; i++ ) {
            delete this->data[i];
        }
        delete this->data;
    }

    
    void Board::init_board() {
        for( int i = 0; i < size; i++ ) {
            for( int j = 0; j < size; j++ ){
                data[i][j] = false;
            }
        }
    }
    
    bool Board::place(Position p) {
        if( p.x < 0 || p.x > size-1 ) return false;
        if( p.y < 0 || p.y > size-1 ) return false;
        if( !issafe(p) ) return false;
        data[p.x][p.y] = true;
        return true;
    }
    
    bool Board::remove(Position p) {
        if( p.x < 0 || p.x > size-1 ) return false;
        if( p.y < 0 || p.y > size-1 ) return false;
        data[p.x][p.y] = false;
        return true;
    }   
    
    void Board::print() {
        std::cout << "=======================" << std::endl;
        for( int i = 0; i < size; i++ ) {
            for( int j = 0; j < size; j++ ){
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "\n\n";
    }

    bool Board::issafe(Position p) {
        // the same row or column
        for( int i = 0; i < size; i++ ) {
            if ( data[p.x][i] || data[i][p.y]) return false;
        }
        
        
        for( int i = p.x, j = p.y; i < size && j < size; i++, j++) {
            if( data[i][j] ) return false;
        }
        
        for( int i = p.x, j = p.y; i < size && j >= 0; i++, j--) {
            if( data[i][j] ) return false;
        }

        for( int i = p.x, j = p.y; i >= 0 && j < size; i--, j++) {
            if( data[i][j] ) return false;
        }
        
        for( int i = p.x, j = p.y; i >= 0 && j >= 0; i--, j--) {
            if( data[i][j] ) return false;
        }
        
        return true;
    }
    
    unsigned int Board::getSize() {
        return size;
    }
    
}
