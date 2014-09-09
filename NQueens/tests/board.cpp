/* 
 * File:   board.cpp
 * Author: lusaisai
 *
 * Created on Sep 10, 2014, 5:21:16 AM
 */

#include <stdlib.h>
#include <iostream>
#include "board.h"

using namespace NQueens;

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "board test 1" << std::endl;
    Board b(5);
    b.place(Position(1,1));
    b.place(Position(2,2));
    b.print();
}

void test2() {
    std::cout << "board test 2" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% board" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (board)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (board)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (board)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (board)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

